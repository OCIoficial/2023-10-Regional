import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Jpaulsen {
    static int p, n, k;
    static int[] t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        p = Integer.parseInt(line[0]);
        n = Integer.parseInt(line[1]);
        k = Integer.parseInt(line[2]);
        line = br.readLine().split(" ");
        t = new int[p];
        for (int i = 0; i < p; i++) {
            t[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(t);
        int sum = 0;
        for (int i = k - 1; i < p; i += n) {
            sum += t[p - 1 - i];
        }
        System.out.println(sum);
    }
}
