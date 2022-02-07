package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class EighthAxiomScheme extends ThreeArgsProof implements AxiomScheme {
    public EighthAxiomScheme(Expression a, Expression b, Expression c) {
        super(a, b, c);
    }

    public static final Expression expression = ExpressionsParser.parse("(A->C)->(B->C)->(A|B->C)");

    @Override
    public Expression getExpression() {
        return expression;
    }
}
