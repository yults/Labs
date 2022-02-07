package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class FifthAxiomScheme extends TwoArgsAxiomScheme {
    public FifthAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("A&B->B");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
