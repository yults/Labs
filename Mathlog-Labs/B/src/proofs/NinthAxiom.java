package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;


import static proofs.Solver.toNatural;

public class NinthAxiom extends TwoArgsAxiom{
    public NinthAxiom(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("(A->B)->(A->!B)->!A");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n + 5, "Ax", hypothesis, map, "A", "A->B", "A->(B->_|_)", "A->(B->_|_)"),
                toNatural(n + 5, "Ax", hypothesis, map, "A", "A->B", "A->(B->_|_)", "A"),
                toNatural(n + 4, "E->", hypothesis, map, "A", "A->B", "A->(B->_|_)", "B->_|_"),
                toNatural(n + 5, "Ax", hypothesis, map, "A", "A->B", "A->(B->_|_)", "A->B"),
                toNatural(n + 5, "Ax", hypothesis, map, "A", "A->B", "A->(B->_|_)", "A"),
                toNatural(n + 4, "E->", hypothesis, map, "A", "A->B", "A->(B->_|_)", "B"),
                toNatural(n + 3, "E->", hypothesis, map, "A", "A->B", "A->(B->_|_)", "_|_"),
                toNatural(n + 2, "I->", hypothesis, map, "A->B", "A->(B->_|_)", "A->_|_"),
                toNatural(n + 1, "I->", hypothesis, map, "A->B", "(A->(B->_|_))->A->_|_"),
                toNatural(n, "I->", hypothesis, map, "(A->B)->((A->(B->_|_))->A->_|_)"));
    }
}
