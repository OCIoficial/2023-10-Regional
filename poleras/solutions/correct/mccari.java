import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class poleras {
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
        int p2 = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            while (p2 > i + k) {
                p2--;
            }

            while (p2 >= i && B[i] > 0) {
                int delta = Math.min(B[i], A[p2]);
                B[i] -= delta;
                A[p2] -= delta;

                if (A[p2] == 0) {
                    p2--;
                }
            }

            if (B[i] > 0) {
                possible = false;
            }
        }

        if (possible) {
            System.out.println("SI");
        } else {
            System.out.println("NO");
        }
    }
}
