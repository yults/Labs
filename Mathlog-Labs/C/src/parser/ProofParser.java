package parser;

import expression.*;
import proofs.*;

import java.lang.reflect.InvocationTargetException;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class ProofParser {
    public static String getProof(Expression expression, Map<Expression, Integer> proved, Map<Expression, Map<Expression, Integer>> mp) {
        return Stream.of(getAxiomScheme(expression), getAxiom(expression),
                getAxiom11(expression), getAxiom12(expression),
                getA9Axiom(expression), getMP(expression, proved, mp),
                getExists(expression, proved, mp), getAll(expression, proved, mp)).
                filter(Objects::nonNull).findFirst().orElse(null);
    }

    private static String getExists(Expression expression, Map<Expression, Integer> proved, Map<Expression, Map<Expression, Integer>> mp) {
        Map<String, Expression> map = new HashMap<>();
        checkAxiomScheme(exists, expression, map);
        Expression x = map.get("x");
        Expression p = map.get("P");
        Expression f = map.get("F");
        if (Stream.of(x, p, f).anyMatch(Objects::isNull)) {
            return null;
        }
        Implication impl = new Implication(p, f);
        String ans = null;
        Integer i = getProved(impl, proved, mp);
        if (i != null) {
            if (getVars(f).contains(x)) {
                ans = "variable " + x + " occurs free in ?-rule";
            } else {
                ans = " ?-intro " + (i + 1);
            }
        }
        return ans;
    }

    private static String getAll(Expression expression, Map<Expression, Integer> proved, Map<Expression, Map<Expression, Integer>> mp) {
        Map<String, Expression> map = new HashMap<>();
        checkAxiomScheme(all, expression, map);
        Expression x = map.get("x");
        Expression p = map.get("P");
        Expression f = map.get("F");
        if (Stream.of(x, p, f).anyMatch(Objects::isNull)) {
            return null;
        }
        Implication impl = new Implication(f, p);
        String ans = null;
        Integer i = getProved(impl, proved, mp);
        if (i != null) {
            if (getVars(f).contains(x)) {
                ans = "variable " + x + " occurs free in @-rule";
            } else {
                ans = " @-intro " + (i + 1);
            }
        }
        return ans;
    }

    private static String getAxiomScheme(Expression expression) {
        return IntStream.range(0, axiomSchemes.size())
                .filter(i -> checkAxiomScheme(axiomSchemes.get(i), expression, new HashMap<>()))
                .mapToObj(i -> " Ax. sch. " + (i + 1)).findFirst().orElse(null);
    }


    private static String getAxiom(Expression expression) {
        return IntStream.range(0, axioms.size())
                .filter(i -> axioms.get(i).equals(expression))
                .mapToObj(i -> " Ax. A" + (i + 1)).
                        findFirst().orElse(null);
    }


    public static Integer getProved(Expression expression, Map<Expression, Integer> proved, Map<Expression, Map<Expression, Integer>> mp) {
        List<Integer> o = new ArrayList<>();
        Optional.ofNullable(proved.get(expression)).ifPresent(o::add);
        if (expression instanceof Implication) {
            Implication implication = (Implication) expression;
            Optional.ofNullable(mp.get(implication.getRight())).flatMap(m -> Optional.ofNullable(m.get(implication.getLeft()))).ifPresent(o::add);
        }
        return o.stream().findFirst().orElse(null);
    }

    private static String getMP(Expression expression, Map<Expression, Integer> proved, Map<Expression, Map<Expression, Integer>> mp) {
        List<String> o = new ArrayList<>();
        Optional.ofNullable(mp.get(expression)).ifPresent(
                it -> it.forEach((e, i) -> Optional.ofNullable(getProved(e, proved, mp))
                        .ifPresent(j -> o.add(" M.P. " + (j + 1) + ", " + (i + 1)))));
        return o.stream().findFirst().orElse(null);
    }

    private final static List<Expression> axioms = List.of(
            ExpressionsParser.parse("a=b->a'=b'"),
            ExpressionsParser.parse("a=b->a=c->b=c"),
            ExpressionsParser.parse("a'=b'->a=b"),
            ExpressionsParser.parse("!a'=0"),
            ExpressionsParser.parse("a+b'=(a+b)'"),
            ExpressionsParser.parse("a+0=a"),
            ExpressionsParser.parse("a*0=0"),
            ExpressionsParser.parse("a*b'=a*b+a")
    );

    private final static List<Expression> axiomSchemes = List.of(
            ExpressionsParser.parse("A->(B->A)"),
            ExpressionsParser.parse("(A->B)->(A->B->C)->(A->C)"),
            ExpressionsParser.parse("A->B->A&B"),
            ExpressionsParser.parse("A&B->A"),
            ExpressionsParser.parse("A&B->B"),
            ExpressionsParser.parse("A->A|B"),
            ExpressionsParser.parse("B->A|B"),
            ExpressionsParser.parse("(A->C)->(B->C)->(A|B->C)"),
            ExpressionsParser.parse("(A->B)->(A->!B)->!A"),
            ExpressionsParser.parse("!!A->A")
    );
    private final static Expression a9Axiom = ExpressionsParser.parse("(O&(@x.P->F))->P");
    private final static Expression axiom11 = ExpressionsParser.parse("(@x.P)->F");
    private final static Expression axiom12 = ExpressionsParser.parse("F->(?x.P)");
    private final static Expression exists = ExpressionsParser.parse("(?x.P)->F");
    private final static Expression all = ExpressionsParser.parse("F->(@x.P)");

    private static String getA9Axiom(Expression expression) {
        Map<String, Expression> map = new HashMap<>();
        if (!checkAxiomScheme(a9Axiom, expression, map)) {
            return null;
        }
        Expression o = map.get("O");
        Expression p = map.get("P");
        Expression f = map.get("F");
        Expression x = map.get("x");
        List<Expression> l = new ArrayList<>();
        l.add(new Zero());
        List<Expression> ll = new ArrayList<>();
        ll.add(new Increment(x));
        if (substitute(p, o, x, l) && substitute(p, f, x, ll)) {
            return " Ax. sch. A9";
        }
        return null;
    }

    private static String getAxiom11(Expression expression) {
        Map<String, Expression> map = new HashMap<>();
        if (!checkAxiomScheme(axiom11, expression, map)) {
            return null;
        }
        Expression p = map.get("P");
        Expression f = map.get("F");
        Expression x = map.get("x");
        List<Expression> l = new ArrayList<>();
        l.add(null);
        if (!substitute(p, f, x, l)) {
            return null;
        }
        if (l.get(0) == null) {
            return " Ax. sch. 11";
        }
        Set<Expression> s = getVars(l.get(0));
        if (isNotFree(f, s)) {
            return "variable " + x + " is not free for term " + l.get(0) + " in @-axiom";
        }
        return " Ax. sch. 11";
    }

    private static String getAxiom12(Expression expression) {
        Map<String, Expression> map = new HashMap<>();
        if (!checkAxiomScheme(axiom12, expression, map)) {
            return null;
        }
        Expression p = map.get("P");
        Expression f = map.get("F");
        Expression x = map.get("x");
        List<Expression> l = new ArrayList<>();
        l.add(null);
        if (!substitute(p, f, x, l)) {
            return null;
        }
        if (l.get(0) == null) {
            return " Ax. sch. 12";
        }
        Set<Expression> s = getVars(l.get(0));

        if (isNotFree(f, s)) {
            return "variable " + x + " is not free for term " + l.get(0) + " in ?-axiom";
        }
        return " Ax. sch. 12";
    }


    private static boolean isNotFree(Expression expression, Set<Expression> vars) {
        if (vars == null) {
            return false;
        }
        if (expression instanceof BinaryExpression) {
            return isNotFree(((BinaryExpression) expression).getLeft(), vars) &&
                    isNotFree(((BinaryExpression) expression).getRight(), vars);
        }
        if (expression instanceof UnaryExpression) {
            return isNotFree(((UnaryExpression) expression).getExpression(), vars);
        }
        if (expression instanceof Pred || expression instanceof Variable) {
            return !vars.contains(expression);
        }
        if (expression instanceof Formula) {
            return vars.contains(((Formula) expression).getVariable()) ||
                    isNotFree(((Formula) expression).getExpression(), vars);
        }
        return false;
    }

    private static Set<Expression> getVars(Expression expression) {
        if (expression instanceof BinaryExpression) {
            return union(getVars(((BinaryExpression) expression).getLeft()),
                    getVars(((BinaryExpression) expression).getRight()));
        }
        if (expression instanceof UnaryExpression) {
            return getVars(((UnaryExpression) expression).getExpression());
        }
        if (expression instanceof Variable || expression instanceof Pred) {
            return Set.of(expression);
        }
        if (expression instanceof Formula) {
            return subtract(getVars(((Formula) expression).getExpression()),
                    ((Formula) expression).getVariable());
        }
        return Set.of();
    }

    private static Set<Expression> subtract(Set<Expression> vars, Expression variable) {
        Set<Expression> s1 = new HashSet<>();
        s1.addAll(vars);
        s1.remove(variable);
        return s1;
    }

    private static Set<Expression> union(Set<Expression> vars, Set<Expression> vars1) {
        Set<Expression> s1 = new HashSet<>();
        s1.addAll(vars);
        s1.addAll(vars1);
        return s1;
    }

    private static boolean substitute(Expression from, Expression to, Expression var, List<Expression> sub) {
        if (from instanceof Variable) {
            if (!from.equals(var)) {
                return from.equals(to);
            }
            if (sub.get(0) == null) {
                sub.add(0, to);
                return true;
            }
            return sub.get(0).equals(to);
        }
        if (from.getClass() != to.getClass()) {
            return false;
        }
        if (from instanceof BinaryExpression && to instanceof BinaryExpression) {
            return substitute(((BinaryExpression) from).getLeft(), ((BinaryExpression) to).getLeft(), var, sub) &&
                    substitute(((BinaryExpression) from).getRight(), ((BinaryExpression) to).getRight(), var, sub);
        }
        if (from instanceof UnaryExpression && to instanceof UnaryExpression) {
            return substitute(((UnaryExpression) from).getExpression(), ((UnaryExpression) to).getExpression(), var, sub);
        }
        if (from instanceof Formula && to instanceof Formula) {
            if (((Formula) from).getSign().equals(((Formula) to).getSign())) {
                if (!((Formula) from).getVariable().equals(var)) {
                    return substitute(((Formula) from).getExpression(), ((Formula) to).getExpression(), var, sub);
                }
                return from.equals(to);
            }
            return false;
        }
        return true;
    }


    private static boolean checkAxiomScheme(Expression axiom, Expression expression, Map<String, Expression> map) {
        if (axiom instanceof Pred) {
            Pred pred = (Pred) axiom;
            String name = pred.getName();
            map.putIfAbsent(name, expression);
            //System.out.println(axiom + " " + expression);
            if (map.containsKey(name)) {
                return map.get(name).equals(expression);
            }
            return true;
        }


        if (axiom.getClass() != expression.getClass()) {
            return false;
        }
        //System.out.println(axiom + " " + expression + " " + axiom.getClass() + " " + expression.getClass());

        if (axiom instanceof Variable) {
            // System.out.println(expression + " "  + axiom);
            Variable variable = (Variable) axiom;
            String name = variable.getName();
            map.putIfAbsent(name, expression);
            if (map.containsKey(name)) {
                return map.get(name).equals(expression);
            }
            return true;
        }
        if (axiom instanceof BinaryExpression) {
            BinaryExpression binaryExpression = (BinaryExpression) expression;
            BinaryExpression binaryAxiom = (BinaryExpression) axiom;
            return checkAxiomScheme(binaryAxiom.getLeft(), binaryExpression.getLeft(), map) && checkAxiomScheme(binaryAxiom.getRight(), binaryExpression.getRight(), map);
        }
        if (axiom instanceof UnaryExpression) {
            UnaryExpression unaryExpression = (UnaryExpression) expression;
            UnaryExpression unaryAxiom = (UnaryExpression) axiom;
            return checkAxiomScheme(unaryAxiom.getExpression(), unaryExpression.getExpression(), map);
        }
        if (axiom instanceof Formula) {
            Formula formulaExpression = (Formula) expression;
            Formula formulaAxiom = (Formula) axiom;
            // System.out.println(formulaAxiom.getVariable().getClass() + " " + formulaExpression.getVariable().getClass());

            return checkAxiomScheme(formulaAxiom.getVariable(), formulaExpression.getVariable(), map)
                    && checkAxiomScheme(formulaAxiom.getExpression(), formulaExpression.getExpression(), map) &&
                    formulaAxiom.getSign().equals(formulaExpression.getSign());
        }
        return true;
    }

}
