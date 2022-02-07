package proofs;

import expression.Expression;

import java.util.Map;

public abstract class ThreeArgsProof implements Proof {
    private final Expression a;
    private final Expression b;
    private final Expression c;
    protected final Map<String, Expression> map;
    public ThreeArgsProof(Expression a, Expression b, Expression c) {
        this.a = a;
        this.b = b;
        this.c = c;
        map = Map.of("A", a, "B", b, "C", c);
    }

    public Expression getA() {
        return a;
    }

    public Expression getB() {
        return b;
    }

    public Expression getC() {
        return c;
    }

    @Override
    public String toString() {
        return this.getClass().getSimpleName() +
                "{a=" + a +
                ", b=" + b +
                ", c=" + c +
                '}';
    }
}
