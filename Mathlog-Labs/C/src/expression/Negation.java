package expression;


public class Negation extends UnaryExpression{


    public Negation(Expression expression) {
        super(expression);
    }

    @Override
    protected String getSymbol() {
        return "!";
    }

    @Override
    public String toString() {
        return "(!"+getExpression()+")";
    }
}
