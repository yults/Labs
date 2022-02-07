package expression;


import java.util.List;
import java.util.Objects;

public abstract class BinaryExpression implements Expression {
    private final Expression left;
    private final Expression right;

    public BinaryExpression(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    protected abstract String getSymbol();

    @Override
    public String toTree() {
        return "(" + getSymbol() + "," + left.toTree() + "," + right.toTree() + ")";
    }

    @Override
    public List<Expression> get(Expression expression) throws Exception {
        if (expression.getClass() == this.getClass()) {
            BinaryExpression binaryExpression = (BinaryExpression) expression;
            return List.of(binaryExpression.getLeft(), binaryExpression.getRight());
        }
        throw new Exception();
    }


    public Expression getLeft() {
        return left;
    }

    public Expression getRight() {
        return right;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        BinaryExpression that = (BinaryExpression) o;
        return Objects.equals(left, that.left) && Objects.equals(right, that.right);
    }

    @Override
    public int hashCode() {
        return Objects.hash(left, right);
    }

    @Override
    public String toString() {
        return "(" + getLeft() + getSymbol() + getRight() + ")";
    }
}
