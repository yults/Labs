package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class SixthAxiom extends AbstractAxiom{
    public static Expression expression = ExpressionsParser.parse("a+0=a");
}
