package proofs;

import expression.Expression;
import parser.ExpressionsParser;

import java.util.List;
import java.util.Set;

import static proofs.Solver.toNatural;

public class SeventhAxiom extends TwoArgsAxiom{
    public SeventhAxiom(Expression a, Expression b) {
        super(a, b);
    }


    public static final Expression expression = ExpressionsParser.parse("B->A|B");

    @Override
    public Expression getExpression() {
        return expression;
    }

    @Override
    public List<String> getNatural(List<Expression> hypothesis, int n) {
        return List.of(toNatural(n + 2, "Ax", hypothesis, map, "B", "B"),
                toNatural(n + 1, "Ir|", hypothesis, map, "B", "A|B"),
                toNatural(n , "I->", hypothesis, map, "B->A|B")
        );
    }
}
