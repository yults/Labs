package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class ThirdAxiomScheme extends TwoArgsAxiomScheme {
    public ThirdAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("A->B->A&B)");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
