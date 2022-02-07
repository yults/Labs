package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class A9Axiom implements AxiomScheme {

    public static Expression expression = ExpressionsParser.parse("(O&(@x.P->I))->P");

    @Override
    public Expression getExpression() {
        return null;
    }
}
