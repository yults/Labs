package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class NinthAxiomScheme extends TwoArgsAxiomScheme {
    public NinthAxiomScheme(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("(A->B)->(A->!B)->!A");

    @Override
    public Expression getExpression() {
        return expression;
    }

}
