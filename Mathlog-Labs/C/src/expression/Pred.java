package expression;

import java.util.Objects;

public class Pred implements Expression {

    private final String name;

    public Pred(String name) {
        this.name = name;
    }


    public String getName() {
        return name;
    }


    @Override
    public int hashCode() {
        return Objects.hash(name);
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pred predicate = (Pred) o;
        return Objects.equals(name, predicate.name);
    }
}
