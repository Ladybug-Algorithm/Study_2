package chap06.picnic;

import java.util.Scanner;

public class Main {

    private static boolean[][] areFriends;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int repeat = sc.nextInt();

        while (repeat-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            boolean[] pairs = new boolean[n];
            areFriends = new boolean[n][n];

            // Initialize list that mutual friend
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                areFriends[a][b] = true;
                areFriends[b][a] = true;
            }

            System.out.println(countParings(pairs));
        }
    }

    /**
     * 친구들을 짝지어 줄 수 있는 경우의 수 반환
     *
     * @param pairs   짝 지어진 경우 true
     */
    private static int countParings(boolean[] pairs) {
        int n = pairs.length;
        int firstFree = -1;

        for (int i = 0; i < n; i++) {
            if (!pairs[i]) {
                firstFree = i;
                break;
            }
        }

        // Base condition: 모든 학생이 짝지어진 경우
        if (firstFree == -1) {
            return 1;
        }

        int ret = 0;

        for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
            if (!pairs[pairWith] && areFriends[firstFree][pairWith]) {
                pairs[firstFree] = pairs[pairWith] = true;
                ret += countParings(pairs);
                pairs[firstFree] = pairs[pairWith] = false;
            }
        }
        return ret;
    }
}
