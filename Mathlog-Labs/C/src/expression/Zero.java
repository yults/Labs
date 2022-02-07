package expression;

import java.util.Objects;

public class Zero implements Expression{
    private final String name = "0";

    public Zero() {
    }

    public String getName() {
        return name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Zero zero = (Zero) o;
        return true;
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }

    @Override
    public String toString() {
        return "0";
    }
}
