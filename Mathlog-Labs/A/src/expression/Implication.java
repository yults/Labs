package expression;

public class Implication extends BinaryExpression {

    public Implication(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    protected String getSymbol() {
        return "->";
    }
}
