package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;
import java.util.Set;

import static proofs.Solver.toNatural;


public class FirstAxiom extends TwoArgsAxiom {
    public FirstAxiom(Expression a, Expression b) {
        super(a, b);
    }

    public static final Expression expression = ExpressionsParser.parse("A->(B->A)");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(
                toNatural(n + 2,  "Ax",hypothesis, map, "A", "B", "A"),
                toNatural(n + 1, "I->",hypothesis, map,  "A", "B->A"),
                toNatural(n, "I->",hypothesis, map,  "A->(B->A)")
        );
    }
}
/*
A|-(C->A)&(B->A)
((C->A)&(B->A))->(C->A)
A->(C->A)
A
C->A
A->(B->A)
A
B->A
(C->A)->(B->A)->((C->A)&(B->A))
(B->A)->((C->A)&(B->A))
((C->A)&(B->A))
 */
