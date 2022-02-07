package expression;

import java.util.List;
import java.util.Objects;

public class Variable implements Expression {

    private final String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public String toTree() {
        return name;
    }

    public String getName() {
        return name;
    }

    @Override
    public List<Expression> get(Expression expression) throws Exception {
        if (expression.getClass() == Variable.class) {
            return List.of(expression);
        }
        throw new Exception();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Variable variable = (Variable) o;
        return Objects.equals(name, variable.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }

    @Override
    public String toString() {
        return name;
    }
}
