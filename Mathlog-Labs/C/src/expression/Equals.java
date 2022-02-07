package expression;

public class Equals extends BinaryExpression{
    public Equals(Expression left, Expression right) {
        super(left, right);

    }

    @Override
    protected String getSymbol() {
        return "=";
    }
}
