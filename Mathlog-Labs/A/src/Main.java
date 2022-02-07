import expression.Expression;
import utils.ExpressionsParser;

import java.io.*;


public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        Expression expression = ExpressionsParser.parse(reader);
        writer.write(expression.toTree());
        writer.flush();
    }
}
