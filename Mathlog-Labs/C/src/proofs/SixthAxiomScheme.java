package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class SixthAxiomScheme extends TwoArgsAxiomScheme {
    public SixthAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("A->A|B");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
