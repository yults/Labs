package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class TenthAxiomScheme extends TwoArgsAxiomScheme {
    public TenthAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }

    public static final Expression expression = ExpressionsParser.parse("A->(!A->B)");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
