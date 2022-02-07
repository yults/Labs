package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;
import java.util.Set;

import static proofs.Solver.toNatural;

public class EighthAxiom extends ThreeArgsProof implements Axiom {
    public EighthAxiom(Expression a, Expression b, Expression c) {
        super(a, b, c);
    }

    public static final Expression expression = ExpressionsParser.parse("(A->C)->(B->C)->(A|B->C)");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(
                toNatural(
                        n + 5,
                        "Ax",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "A",
                        "A->C"
                ),
                toNatural(
                        n + 5,
                        "Ax",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "A",
                        "A"
                ),
                toNatural(
                        n + 4,
                        "E->",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "A",
                        "C"
                ),
                toNatural(
                        n + 5,
                        "Ax",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "B",
                        "B->C"
                ),
                toNatural(
                        n + 5,
                        "Ax",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "B",
                        "B"
                ),
                toNatural(
                        n + 4,
                        "E->",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "B",
                        "C"
                ),
                toNatural(
                        n + 4,
                        "Ax",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "A|B"
                ),
                toNatural(
                        n + 3,
                        "E|",
                        hypothesis,
                        map,
                        "A->C",
                        "B->C",
                        "A|B",
                        "C"
                ),
                toNatural(n + 2, "I->", hypothesis, map, "A->C", "B->C", "A|B->C"),
                toNatural(
                        n + 1,
                        "I->",
                        hypothesis,
                        map,
                        "A->C",
                        "(B->C)->(A|B->C)"
                ),
                toNatural(n, "I->", hypothesis, map, "(A->C)->((B->C)->(A|B->C))")
        );
    }
}
