package proofs;

import expression.Expression;
import parser.ExpressionsParser;

public class FourthAxiom extends AbstractAxiom{
    public static Expression expression = ExpressionsParser.parse("!a'=0");
}
