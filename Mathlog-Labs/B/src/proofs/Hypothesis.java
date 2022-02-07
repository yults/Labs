package proofs;

import expression.Expression;

import java.util.List;


import static proofs.Solver.toNatural;

public class Hypothesis extends OneArgProof {

    public Hypothesis(Expression a) {
        super(a);
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n, "Ax", hypothesis, map, "A"));
    }

    @Override
    public String toString() {
        return "Hypothesis " + getA();
    }
}
