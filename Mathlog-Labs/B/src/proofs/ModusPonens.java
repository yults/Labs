package proofs;

import expression.Expression;

import java.util.List;
import java.util.Map;

import static proofs.Solver.toNatural;

public class ModusPonens implements Proof{
    private final Expression a;
    private final int i;
    private final int j;
    private final Map<String, Expression> map;


    public ModusPonens(Expression a, int i, int j) {
        this.a = a;
        this.i = i;
        this.j = j;
        map = Map.of("A", a);
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
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n, "E->", hypothesis, map,"A"));
    }

    @Override
    public String toString() {
        return "ModusPonens{" +
                "a=" + a +
                '}';
    }
}
