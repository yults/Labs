package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;

import static proofs.Solver.toNatural;

public class SixthAxiom extends TwoArgsAxiom {
    public SixthAxiom(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("A->A|B");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n + 2,"Ax", hypothesis, map, "A", "A"),
                toNatural(n + 1,"Il|", hypothesis, map, "A", "A|B"),
                toNatural(n , "I->", hypothesis, map, "A->A|B")
        );
    }
}
