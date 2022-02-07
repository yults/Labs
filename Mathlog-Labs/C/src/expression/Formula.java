package expression;

import java.util.Objects;

public class Formula implements Expression {
    private final String sign;
    private final Expression variable;
    private final Expression expression;

    public Formula(String sign, Expression variable, Expression expression) {
        this.sign = sign;
        this.variable = variable;
        this.expression = expression;
    }

    public String getSign() {
        return sign;
    }

    public Expression getVariable() {
        return variable;
    }

    public Expression getExpression() {
        return expression;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Formula formula = (Formula) o;
        return Objects.equals(sign, formula.sign) && Objects.equals(variable, formula.variable) && Objects.equals(expression, formula.expression);
    }

    @Override
    public int hashCode() {
        return Objects.hash(sign, variable, expression);
    }

    @Override
    public String toString() {
        return "(" + sign + variable + "." + expression + ")";
    }
}
