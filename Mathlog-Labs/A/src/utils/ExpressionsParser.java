package utils;

import parser.ExpressionLexer;
import parser.ExpressionParser;
import expression.Expression;
import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.TokenStream;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

public class ExpressionsParser {

    public static Expression parse(BufferedReader reader) throws IOException {
            String statement = reader.readLine();
            ANTLRInputStream is = new ANTLRInputStream(statement);
            ExpressionLexer lexer = new ExpressionLexer(is);
            TokenStream ts = new CommonTokenStream(lexer);
            ExpressionParser parser = new ExpressionParser(ts);
            return parser.expression().expr;
    }

}
