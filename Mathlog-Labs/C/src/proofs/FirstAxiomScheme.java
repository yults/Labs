package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class FirstAxiomScheme extends TwoArgsAxiomScheme {
    public FirstAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }

    public static final Expression expression = ExpressionsParser.parse("A->(B->A)");

    @Override
    public Expression getExpression() {
        return expression;
    }

}
