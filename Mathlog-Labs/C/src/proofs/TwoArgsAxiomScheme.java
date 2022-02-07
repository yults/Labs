package proofs;

import expression.Expression;
import java.util.Map;

public abstract class TwoArgsAxiomScheme implements AxiomScheme {
    private final Expression a;
    private final Expression b;
    protected final Map<String, Expression> map;

    public TwoArgsAxiomScheme(Expression a, Expression b) {
        this.a = a;
        this.b = b;
        map = Map.of("A", a, "B", b);
    }

    public Expression getA() {
        return a;
    }

    public Expression getB() {
        return b;
    }

    @Override
    public String toString() {
        return this.getClass().getSimpleName() +
                "{a=" + a +
                ", b=" + b +
                '}';
    }
}
