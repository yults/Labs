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
    private static class Result {
        private final List<Proof> proofs;
        private final List<Expression> hypothesis;

        public Result(List<Proof> proofs, List<Expression> hypothesis) {
            this.proofs = proofs;
            this.hypothesis = hypothesis;
        }

        public List<Proof> getProofs() {
            return proofs;
        }

        public List<Expression> getHypothesis() {
            return hypothesis;
        }
    }

    public static void toNatural(BufferedReader reader, BufferedWriter writer) throws IOException {
        Result result = getProofs(reader, writer);
        if (result == null) {
            return;
        }
        List<Proof> proofs = result.getProofs();
        List<Expression> hypothesis = result.getHypothesis();
        toNatural(proofs, hypothesis, writer, proofs.size() - 1, 0);
        writer.flush();
    }

    private static void toNatural(List<Proof> proofs, List<Expression> hypothesis, BufferedWriter writer, int i, int n) {
        Proof proof = proofs.get(i);
        if (proof instanceof ModusPonens) {
            ModusPonens modusPonens = (ModusPonens) proof;
            toNatural(proofs, hypothesis, writer, modusPonens.getI(), n + 1);
            toNatural(proofs, hypothesis, writer, modusPonens.getJ(), n + 1);

        }
        proof.getNatural(hypothesis, n).forEach(it -> {
            try {
                writer.write(it + "\n");
            } catch (IOException ignored) {
            }
        });
    }

    private static Result getProofs(BufferedReader reader, BufferedWriter writer) throws IOException {
        String prevLine = reader.readLine().replace(" ", "");
        String[] f = prevLine.split("\\|-");
        Expression exp = ExpressionsParser.parse(f[1]);
        List<Expression> hypothesis = Arrays.stream(f[0].split(",")).map(ExpressionsParser::parse).filter(Objects::nonNull).collect(Collectors.toList());
        Map<Expression, Integer> proofed = new HashMap<>();
        Map<Expression, Map<Expression, Integer>> mp = new HashMap<>();
        for (int i = 0; i < hypothesis.size(); i++) {
            proofed.putIfAbsent(hypothesis.get(i), i);
        }
        List<Proof> proofs = new ArrayList<>();
        String line;
        String error = null;
        for (int i = 0; (line = reader.readLine()) != null; i++) {
            line = line.replace(" ", "");
            Expression expression = ExpressionsParser.parse(line);
            Proof proof = ProofParser.getProof(expression, proofed, mp);
            if (proof == null) {
                if (error == null) {
                    error = "Proof is incorrect at line " + (i + 2);
                }
            } else {
                proofs.add(proof);
                if (expression instanceof Implication) {
                    Implication implication = (Implication) expression;
                    mp.putIfAbsent(implication.getRight(), new HashMap<>());
                    mp.get(implication.getRight()).put(implication.getLeft(), i);
                } else {
                    proofed.put(expression, i);
                }
            }
            prevLine = line;
        }
        if (!ExpressionsParser.parse(prevLine).equals(exp)) {
            writer.write("The proof does not prove required expression");
            writer.flush();
            return null;
        }
        if (error != null) {
            writer.write(error);
            writer.flush();
            return null;
        }
        return new Result(proofs, hypothesis);
    }

    static String toNatural(int n, String s, List<Expression> hypothesis, Map<String, Expression> map, String... args) {
        List<Expression> l = Arrays.stream(args).map(ExpressionsParser::parse).map(it -> ExpressionsParser.transform(it, map)).collect(Collectors.toList());
        List<Expression> ll = new ArrayList<>(hypothesis);
        ll.addAll(l);
        return   "[" + n + "] " +
                ll.subList(0, ll.size() - 1).stream().map(Object::toString).collect(Collectors.joining(",")) + "|-" +
                str(ll.get(ll.size() - 1).toString()) +
                " [" + s + "]";

    }

    private static String str(String s) {
        int i = 0;
        int j = s.length();
        if (s.charAt(0) == '(') {
            i++;
        }
        if (s.charAt(j - 1) == ')') {
            j--;
        }
        return s.substring(i, j);
    }


}
