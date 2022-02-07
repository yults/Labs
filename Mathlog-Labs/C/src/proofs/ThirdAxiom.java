package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class ThirdAxiom extends AbstractAxiom{
    public static Expression expression = ExpressionsParser.parse("a'=b'->a=b");
}
