import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Jpaulsen {
    static int[] count;
    static ArrayList<Pair> good = new ArrayList<>();
    static ArrayList<Pair> bad = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);
        long min = Integer.parseInt(line[2]);
        long max = Integer.parseInt(line[3]) + 1;
        count = new int[10000];
        line = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            int rate = Integer.parseInt(line[i]);
            count[rate - 1]++;
        }
        good.add(new Pair(0, 0));
        bad.add(new Pair(0, 0));
        for (int r = 10000; r >= 1; r--) {
            long c = count[r - 1];
            if (c == 0) continue;
            good.add(new Pair((min + r - 1) / r, c));
            bad.add(new Pair((max + r - 1) / r, c));
        }
        for (int i = 0; i < good.size() - 1; i++) {
            good.get(i + 1).c += good.get(i).c;
            bad.get(i + 1).c += bad.get(i).c;
        }
        while (q-- > 0) {
            long t = Long.parseLong(br.readLine());
            int goodIndex = binarySearch(good, 0, good.size() - 1, t);
            int badIndex = binarySearch(bad, 0, bad.size() - 1, t);
            long goodCount = good.get(goodIndex).c;
            long badCount = bad.get(badIndex).c;
            sb.append(goodCount - badCount);
            sb.append('\n');
        }
        System.out.print(sb);
    }

    public static int binarySearch(ArrayList<Pair> values, int l, int r, long t) {
        if (l == r) return l;
        int mid = (l + r + 1) / 2;
        Pair value = values.get(mid);
        if (value.t <= t) return binarySearch(values, mid, r, t);
        return binarySearch(values, l, mid - 1, t);
    }
}

class Pair {
    long t, c;

    Pair(long t, long c) {
        this.t = t;
        this.c = c;
    }

    @Override
    public String toString() {
        return t + ", " + c;
    }
}