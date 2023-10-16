import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Main {
    static class Torrent implements Comparable<Torrent> {
        int s, p, index;

        Torrent(int s, int p, int index) {
            this.s = s;
            this.p = p;
            this.index = index;
        }

        @Override
        public int compareTo(Torrent t) {
            if (s == t.s) {
                if (p == t.p) {
                    Random rand = new Random();
                    return rand.nextInt(2) == 0 ? -1 : 1;
                }
                return p - t.p;
            }
            return t.s - s;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Torrent torrent = new Torrent(-1, 100000000, -1);

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int s = Integer.parseInt(input[0]);
            int p = Integer.parseInt(input[1]);

            Torrent t = new Torrent(s, p, i + 1);

            if (t.compareTo(torrent) < 0) {
                torrent = t;
            }
        }

        System.out.println(torrent.index);
    }
}
