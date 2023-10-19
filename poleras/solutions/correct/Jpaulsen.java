import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class poleras {
    static int n, k;
    static int[] a, b;

    public static boolean solution() {
        int j = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            while (j >= i && b[i] > 0) {
                if (j - i <= k && a[j] > 0) {
                    int s = Math.min(b[i], a[j]);
                    b[i] -= s;
                    a[j] -= s;
                } else {
                    j--;
                }
            }
            if (b[i] > 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        k = Integer.parseInt(line[1]);
        a = new int[n];
        b = new int[n];
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(line[i]);
        }
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(line[i]);
        }
        if (solution()) System.out.println("SI");
        else System.out.println("NO");
    }
}
