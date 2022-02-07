package parser;

import expression.*;
import proofs.*;

import java.lang.reflect.InvocationTargetException;
import java.util.*;

public class ProofParser {
    public static Proof getProof(Expression expression, Map<Expression, Integer> proofed, Map<Expression, Map<Expression, Integer>> mp) {
        List<Proof> o = new ArrayList<>();
        Optional.ofNullable(getAxiom(expression)).ifPresent(o::add);
        Optional.ofNullable(getMP(expression, proofed, mp)).ifPresent(o::add);
        Optional.ofNullable(proofed.get(expression)).ifPresent(it -> o.add(new Hypothesis(expression)));
        return o.stream().findFirst().orElse(null);
    }

    private static Integer getProofed(Expression expression, Map<Expression, Integer> proofed, Map<Expression, Map<Expression, Integer>> mp) {
        List<Integer> o = new ArrayList<>();
        Optional.ofNullable(proofed.get(expression)).ifPresent(o::add);
        if (expression instanceof Implication) {
            Implication implication = (Implication) expression;
            Optional.ofNullable(mp.get(implication.getRight())).flatMap(m -> Optional.ofNullable(m.get(implication.getLeft()))).ifPresent(o::add);
        }
        return o.stream().findFirst().orElse(null);
    }

    private static Proof getMP(Expression expression, Map<Expression, Integer> proofed, Map<Expression, Map<Expression, Integer>> mp) {
        List<Proof> o = new ArrayList<>();
        Optional.ofNullable(mp.get(expression)).ifPresent(
                it -> it.forEach((e, i) -> Optional.ofNullable(getProofed(e, proofed, mp))
                        .ifPresent(j -> o.add(new ModusPonens(expression, i, j)))));
        return o.stream().findFirst().orElse(null);
    }

    private final static List<Class<? extends Axiom>> axioms = List.of(
            FirstAxiom.class, SecondAxiom.class, ThirdAxiom.class, FourthAxiom.class, FifthAxiom.class, SixthAxiom.class, SeventhAxiom.class, EighthAxiom.class, NinthAxiom.class, TenthAxiom.class
    );

    private static Axiom getAxiom(Expression expression) {
        return axioms.stream().map(it -> tryParse(expression, it)).filter(Objects::nonNull).findFirst().orElse(null);
    }

    private static Axiom tryParse(Expression expression, Class<? extends Axiom> proof) {
        try {
            Map<String, Expression> map = new HashMap<>();
            boolean isAxiom = checkAxiom((Expression) proof.getField("expression").get(null), expression, map);
            if (!isAxiom) {
                return null;
            }
            Expression a = map.get("A");
            Expression b = map.get("B");
            Expression c = map.get("C");
            Expression[] e = new Expression[]{a, b, c};
            e = Arrays.stream(e).filter(Objects::nonNull).toArray(Expression[]::new);
            return (Axiom) proof.getConstructors()[0].newInstance((Object[]) e);
        } catch (NoSuchFieldException | InstantiationException | IllegalAccessException | InvocationTargetException | IllegalArgumentException ex) {
            return null;
        }
    }

    private static boolean checkAxiom(Expression axiom, Expression expression, Map<String, Expression> map) {
        if (axiom instanceof Variable) {
            Variable variable = (Variable) axiom;
            String name = variable.getName();
            map.putIfAbsent(name, expression);
            if (map.containsKey(name)) {
                return map.get(name).equals(expression);
            }
            return true;
        }
        if (axiom.getClass() != expression.getClass()) {
            return false;
        }
        if (axiom instanceof BinaryExpression) {
            BinaryExpression binaryExpression = (BinaryExpression) expression;
            BinaryExpression binaryAxiom = (BinaryExpression) axiom;
            return checkAxiom(binaryAxiom.getLeft(), binaryExpression.getLeft(), map) && checkAxiom(binaryAxiom.getRight(), binaryExpression.getRight(), map);
        }
        if (axiom instanceof UnaryExpression) {
            UnaryExpression unaryExpression = (UnaryExpression) expression;
            UnaryExpression unaryAxiom = (UnaryExpression) axiom;
            return checkAxiom(unaryAxiom.getExpression(), unaryExpression.getExpression(), map);
        }
        return true;
    }
}
