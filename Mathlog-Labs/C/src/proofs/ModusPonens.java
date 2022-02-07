package proofs;

import expression.Expression;

import java.util.List;
import java.util.Map;

public class ModusPonens implements Proof{
    private final Expression a;
    private final int i;
    private final int j;


    public ModusPonens(Expression a, int i, int j) {
        this.a = a;
        this.i = i;
        this.j = j;
    }

    public Expression getA() {
        return a;
    }

    public int getI() {
        return i;
    }

    public int getJ() {
        return j;
    }

    @Override
    public String toString() {
        return "ModusPonens{" +
                "a=" + a +
                '}';
    }
}
