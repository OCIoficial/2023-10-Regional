import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

class paltas {
    static int n, q, min, max;
    static int[] rates;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] line = br.readLine().split(" ");
        n = Integer.parseInt(line[0]);
        q = Integer.parseInt(line[1]);
        min = Integer.parseInt(line[2]);
        max = Integer.parseInt(line[3]);
        rates = new int[n];
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            rates[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(rates);
        while (q-- > 0) {
            int t = Integer.parseInt(br.readLine());
            int goodIndex = binarySearch(0, n, t, min);
            int badIndex = binarySearch(0, n, t, max + 1);
            sb.append(badIndex - goodIndex);
            sb.append('\n');
        }
        System.out.print(sb);
    }

    public static int binarySearch(int l, int r, int t, int v) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int rate = rates[mid];
        if (rate * t >= v) return binarySearch(l, mid, t, v);
        return binarySearch(mid + 1, r, t, v);
    }
}
