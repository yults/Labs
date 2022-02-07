package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;


import static proofs.Solver.toNatural;

public class SecondAxiom extends ThreeArgsProof implements Axiom {
    public SecondAxiom(Expression a, Expression b, Expression c) {
        super(a, b, c);
    }


    public static final Expression expression = ExpressionsParser.parse("(A->B)->(A->B->C)->(A->C)");

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
                        "A->B",
                        "A->(B->C)",
                        "A",
                        "A->(B->C)"
                ),
                toNatural(n + 5, "Ax", hypothesis, map, "A->B", "A->(B->C)", "A", "A"),
                toNatural(
                        n + 4,
                        "E->",
                        hypothesis,
                        map,
                        "A->B",
                        "A->(B->C)",
                        "A",
                        "B->C"
                ),
                toNatural(
                        n + 5,
                        "Ax",
                        hypothesis,
                        map,
                        "A->B",
                        "A->(B->C)",
                        "A",
                        "A->B"
                ),
                toNatural(n + 5, "Ax", hypothesis, map, "A->B", "A->(B->C)", "A", "A"),
                toNatural(
                        n + 4,
                        "E->",
                        hypothesis,
                        map,
                        "A->B",
                        "A->(B->C)",
                        "A",
                        "B"
                ),
                toNatural(
                        n + 3,
                        "E->",
                        hypothesis,
                        map,
                        "A->B",
                        "A->(B->C)",
                        "A",
                        "C"
                ),
                toNatural(
                        n + 2,
                        "I->",
                        hypothesis,
                        map,
                        "A->B",
                        "A->(B->C)",
                        "A->C"
                ),
                toNatural(
                        n + 1,
                        "I->",
                        hypothesis,
                        map,
                        "A->B",
                        "(A->(B->C))->(A->C)"
                ),
                toNatural(
                        n,
                        "I->",
                        hypothesis,
                        map,
                        "(A->B)->(A->(B->C))->(A->C)"
                )
        );
    }
}
