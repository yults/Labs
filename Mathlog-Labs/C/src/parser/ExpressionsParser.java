package parser;

import expression.BinaryExpression;
import expression.UnaryExpression;
import expression.Pred;

import expression.Expression;
import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.TokenStream;
import parser.ExpressionLexer;
import parser.ExpressionParser;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Map;



public class ExpressionsParser {

    public static Expression parse(BufferedReader reader) throws IOException {
        String statement = reader.readLine();
        return parse(statement);
    }

    public static Expression parse(String statement) {
        ANTLRInputStream is = new ANTLRInputStream(statement);
        ExpressionLexer lexer = new ExpressionLexer(is);
        TokenStream ts = new CommonTokenStream(lexer);
        ExpressionParser parser = new ExpressionParser(ts);
        return parser.expression().expr;
    }


}
