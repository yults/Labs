package expression;

public class Conjunction extends BinaryExpression {

    public Conjunction(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    protected String getSymbol() {
        return "&";
    }
}
