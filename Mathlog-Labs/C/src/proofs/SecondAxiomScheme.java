package proofs;

import expression.Expression;
import parser.ExpressionsParser;


public class SecondAxiomScheme extends ThreeArgsProof implements AxiomScheme {
    public SecondAxiomScheme(Expression a, Expression b, Expression c) {
        super(a, b, c);
    }


    public static final Expression expression = ExpressionsParser.parse("(A->B)->(A->B->C)->(A->C)");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
