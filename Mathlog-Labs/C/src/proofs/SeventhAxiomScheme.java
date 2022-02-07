package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class SeventhAxiomScheme extends TwoArgsAxiomScheme {
    public SeventhAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("B->A|B");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
