package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class SecondAxiom extends AbstractAxiom{
    public static Expression expression = ExpressionsParser.parse("a=b->a=c->b=c");
}
