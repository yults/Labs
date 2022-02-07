package expression;

public class Increment extends UnaryExpression {
    public Increment(Expression expression) {
        super(expression);
    }

    @Override
    protected String getSymbol() {
        return "'";
    }

    @Override
    public String toString() {
        return "" + getExpression() + "'";
    }
}
