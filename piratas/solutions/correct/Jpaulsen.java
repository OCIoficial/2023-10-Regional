import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Jpaulsen {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int maxSeeds = -1, minPeers = Integer.MAX_VALUE, bestIndex = -1;
        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            int s = Integer.parseInt(line[0]);
            int p = Integer.parseInt(line[1]);
            if (s > maxSeeds) {
                maxSeeds = s;
                minPeers = p;
                bestIndex = i;
            } else if (s == maxSeeds && p < minPeers) {
                minPeers = p;
                bestIndex = i;
            }
        }
        System.out.println(bestIndex + 1);
    }
}
