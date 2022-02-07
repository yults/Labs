import proofs.Solver;

import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        Solver.toNatural(reader, writer);
        writer.flush();
    }
}
