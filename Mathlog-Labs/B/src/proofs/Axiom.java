package proofs;

import expression.Expression;

public interface Axiom extends Proof{
    Expression getExpression();
}
