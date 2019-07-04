package chap07.fence;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
    );
    private static int[] fences;

    public static void main(String[] args) throws IOException {
        int c = Integer.parseInt(br.readLine());

        while (c-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");

            fences = new int[n];
            for (int i = 0; i < n; i++) {
                fences[i] = Integer.parseInt(line[i]);
            }
            System.out.println(solution(0, n - 1));
        }
        br.close();
    }

    /**
     * 1. 가장 큰 직사각형이 왼쪽에 있다.
     * 2. 가장 큰 직사각형이 오른쪽에 있다.
     * 3. 가장 큰 직사각형이 왼쪽 과 오른쪽에 걸쳐있다.
     */
    private static int solution(int left, int right) {
        // Base condition
        if (left == right) {
            return fences[left];
        }
        int mid = (left + right) / 2;
        // 좌, 우 분할 (1, 2) 문제 해결
        int ret = Math.max(solution(left, mid), solution(mid + 1, right));

        int lo = mid;
        int hi = mid + 1;
        int height = Math.min(fences[lo], fences[hi]);

        // 길이가 2인 울타리 넓이 확인
        ret = Math.max(ret, height * 2);

        // 높이가 큰 쪽으로 확장
        while (left < lo || hi < right) {
            if (hi < right && (lo == left || fences[lo - 1] < fences[hi + 1])) {
                ++hi;
                height = Math.min(height, fences[hi]);
            } else {
                --lo;
                height = Math.min(height, fences[lo]);
            }
            ret = Math.max(ret, height * (hi - lo + 1));
        }
        return ret;
    }
}
