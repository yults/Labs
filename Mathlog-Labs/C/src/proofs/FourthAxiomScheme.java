package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class FourthAxiomScheme extends TwoArgsAxiomScheme {
    public FourthAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("A&B->A");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
