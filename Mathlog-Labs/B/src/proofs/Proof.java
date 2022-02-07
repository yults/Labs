package proofs;

import expression.Expression;

import java.util.List;
import java.util.Set;

public interface Proof {
    List<String> getNatural(List<Expression> hypothesis, int n);
}
