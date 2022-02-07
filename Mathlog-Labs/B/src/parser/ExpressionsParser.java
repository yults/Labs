package parser;

import expression.BinaryExpression;
import expression.UnaryExpression;
import expression.Variable;

import expression.Expression;
import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.TokenStream;

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

    public static Expression transform(Expression expression, Map<String, Expression> map) {
        if (expression instanceof BinaryExpression) {
            BinaryExpression binaryExpression = (BinaryExpression) expression;
            return getInstance(expression,
                    transform(binaryExpression.getLeft(), map),
                    transform(binaryExpression.getRight(), map));
        }
        if (expression instanceof UnaryExpression) {
            UnaryExpression unaryExpression = (UnaryExpression) expression;
            return getInstance(expression,
                    transform(unaryExpression.getExpression(), map));
        }
        if (expression instanceof Variable) {
            if(((Variable) expression).getName().equals("_|_")){
                return new Variable("_|_");
            }
            if(map.get(((Variable) expression).getName()) == null){
                return new Variable("{" + ((Variable) expression).getName()+"}");
            }
            return map.get(((Variable) expression).getName());
        }
        return null;
    }

    private static Expression getInstance(Expression expression, Object... args) {
        try {
            return (Expression) expression.getClass().getConstructors()[0].newInstance(args);
        } catch (Exception e) {
            return null;
        }
    }
}
