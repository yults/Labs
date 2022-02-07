package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;
import java.util.Set;

import static proofs.Solver.toNatural;

public class FifthAxiom extends TwoArgsAxiom{
    public FifthAxiom(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("A&B->B");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n + 2, "Ax", hypothesis, map, "A&B", "A&B"),
                toNatural(n + 1, "El&", hypothesis, map, "A&B", "A"),
                toNatural(n ,"I->", hypothesis, map, "A&B->A")
        );
    }
}
