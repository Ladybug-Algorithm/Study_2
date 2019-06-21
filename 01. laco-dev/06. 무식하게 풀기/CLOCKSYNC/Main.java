package chap06.clocksync;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * INF 를 두어서 불가능한 경우를 준비하는 것이 좋다.
 * 모든 경우를 준비할 때 String[] 처럼 특수하게 만들어 두는 것이 좋다.
 * Base condition 확인은 다음 재귀에서 처음에 확인한다.
 * 최소값을 확인할 때 Math.min 을 통해 기존 값과 다음 재귀를 같이 확인한다.
 */
public class Main {
    private static final int INF = 9999;
    private static String[] links = {
            "xxx.............",
            "...x...x.x.x....",
            "....x.....x...xx",
            "x...xxxx........",
            "......xxx.x.x...",
            "x.x...........xx",
            "...x..........xx",
            "....xx.x......xx",
            ".xxxxx..........",
            "...xxx...x...x.."
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = Integer.parseInt(br.readLine());

        while (c-- > 0) {
            String[] test = br.readLine().split(" ");
            int[] clocks = new int[test.length];

            for (int i = 0; i < test.length; i++) {
                clocks[i] = Integer.parseInt(test[i]);
            }
            int sol = minClock(clocks, 0);
            // 불가한 경우 -1 출력
            System.out.println(sol == INF ? -1 : sol);
        }
        br.close();
    }

    // 최소의 수로 모든 시계를 12시로 만들수 있는 수 반환. 불가하다면 INF 반환
    private static int minClock(int[] clocks, int link) {
        // Base condition: 모든 연결 확인 완료
        if (link == links.length) {
            return areAll12(clocks) ? 0 : INF;
        }

        int ret = INF;
        // 스위치를 4번 켜면 원래대로 돌아온다.
        for (int i = 0; i < 4; i++) {
            ret = Math.min(ret, i + minClock(clocks, link + 1));
            clock(clocks, link);
        }
        return ret;
    }

    // 모든 시계가 12시에 있는지 확인
    private static boolean areAll12(int[] clocks) {
        for (int clock : clocks) {
            if (clock != 12) {
                return false;
            }
        }
        return true;
    }

    // 시계 스위치 동작
    private static void clock(int[] clocks, int link) {
        for (int i = 0; i < 16; i++) {
            if (links[link].charAt(i) == 'x') {
                clocks[i] += 3;
                if (clocks[i] == 15) {
                    clocks[i] = 3;
                }
            }
        }
    }
}
