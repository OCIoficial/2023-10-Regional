import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class poleras {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] A = new int[n];
        int[] B = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        boolean possible = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = Math.min(n - 1, i + k); j >= i; j--) {
                int delta = Math.min(B[i], A[j]);
                B[i] -= delta;
                A[j] -= delta;
            }

            if (B[i] > 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            System.out.println("SI");
        } else {
            System.out.println("NO");
        }
    }
}
