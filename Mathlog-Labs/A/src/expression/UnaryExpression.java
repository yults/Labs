package expression;

import java.util.Objects;

public abstract class UnaryExpression implements Expression{
    private final Expression expression;

    public UnaryExpression(Expression expression) {
        this.expression = expression;
    }

    public Expression getExpression() {
        return expression;
    }

    protected abstract String getSymbol();

    @Override
    public String toTree() {
        return "(" + getSymbol() + expression.toTree() + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        UnaryExpression that = (UnaryExpression) o;
        return Objects.equals(expression, that.expression);
    }

    @Override
    public int hashCode() {
        return Objects.hash(expression);
    }
}
