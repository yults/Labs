package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class FirstAxiom extends AbstractAxiom{
    public static Expression expression = ExpressionsParser.parse("a=b->a'=b'");
}
