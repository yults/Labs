package expression;

public class Disjunction extends BinaryExpression {


    public Disjunction(Expression left, Expression right) {
        super(left, right);
    }

    @Override
    protected String getSymbol() {
        return "|";
    }

}
