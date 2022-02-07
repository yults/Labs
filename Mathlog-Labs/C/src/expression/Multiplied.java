package expression;

public class Multiplied extends BinaryExpression{
    public Multiplied(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    protected String getSymbol() {
        return "*";
    }
}
