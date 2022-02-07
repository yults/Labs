package expression;

public class Term extends BinaryExpression{
    public Term(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    protected String getSymbol() {
        return "+";
    }
}
