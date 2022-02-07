package proofs;

import expression.Expression;

import java.util.Map;

public abstract class OneArgProof implements Proof {
    private final Expression a;
    protected final Map<String, Expression> map;
    public OneArgProof(Expression a) {
        this.a = a;
        map = Map.of("A", a);
    }

    public Expression getA() {
        return a;
    }

}
