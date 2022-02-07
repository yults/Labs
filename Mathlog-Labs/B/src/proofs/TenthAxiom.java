package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;

import static proofs.Solver.toNatural;

public class TenthAxiom extends TwoArgsAxiom {
    public TenthAxiom(Expression a, Expression b) {
        super(a, b);
    }

    public static final Expression expression = ExpressionsParser.parse("A->(!A->B)");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n + 4, "Ax", hypothesis, map, "A", "A->_|_", "A->_|_"),
                toNatural(n + 4, "Ax", hypothesis, map, "A", "A->_|_", "A"),
                toNatural(n + 3, "E->", hypothesis, map, "A", "A->_|_", "_|_"),
                toNatural(n + 2, "E_|_", hypothesis, map, "A", "A->_|_", "B"),
                toNatural(n + 1, "I->", hypothesis, map, "A", "(A->_|_)->B"),
                toNatural(n , "I->", hypothesis, map, "A->((A->_|_)->B)")
        );
        }
}
