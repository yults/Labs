package proofs;

import expression.Expression;
import expression.Implication;
import parser.ExpressionsParser;
import parser.ProofParser;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class Solver {

    public static void getProofs(BufferedReader reader, BufferedWriter writer) throws IOException {
        String prevLine = reader.readLine().replace(" ", "");
        String[] f = prevLine.split("\\|-");
        Expression exp = ExpressionsParser.parse(f[1]);
        List<Expression> hypothesis = Arrays.stream(f[0].split(",")).map(ExpressionsParser::parse).filter(Objects::nonNull).collect(Collectors.toList());
        Map<Expression, Integer> proved = new HashMap<>();
        Map<Expression, Map<Expression, Integer>> mp = new HashMap<>();
        for (int i = 0; i < hypothesis.size(); i++) {
            proved.putIfAbsent(hypothesis.get(i), i);
        }
        String line;
        writer.write("|-" + exp + "\n");
        for (int i = 0; (line = reader.readLine()) != null; i++) {
            line = line.replace(" ", "");
            Expression expression = ExpressionsParser.parse(line);
            String str = ProofParser.getProof(expression, proved, mp);
            if (str == null) {
                writer.write("Expression " + (i + 1) + " is not proved.\n");
                return;
            }

            if (str.contains("variable")) {
                writer.write("Expression " + (i + 1) + ": " + str + ".\n");
                return;
            }
            if (expression instanceof Implication) {
                Implication implication = (Implication) expression;
                mp.putIfAbsent(implication.getRight(), new HashMap<>());
                mp.get(implication.getRight()).put(implication.getLeft(), i);
            } else {
                proved.put(expression, i);
            }
            writer.write("[" + (i + 1) + "." + str + "] " + expression + "\n");
        }
        if (ProofParser.getProved(exp, proved, mp) == null) {
            writer.write("The proof proves different expression.");
        }
    }


}
