package chap06.boardcover;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    // 맨 왼쪽 위부터시작한다고 하면, 블록을 놓을 수 있는 경우는 총 4가지다.
    private static int[][][] coverType = {
            {{0, 0}, {1, 0}, {0, 1}},
            {{0, 0}, {1, 0}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 1}},
            {{0, 0}, {0, 1}, {-1, 1}}
    };

    private static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int loop = Integer.parseInt(br.readLine());

        // Loop testcase
        while (loop-- > 0) {
            String[] line = br.readLine().split(" ");
            int h = Integer.parseInt(line[0]);
            int w = Integer.parseInt(line[1]);

            board = new int[h][w];

            for (int i = 0; i < h; i++) {
                String figure = br.readLine();
                for (int j = 0; j < w; j++) {
                    if (figure.charAt(j) == '#') {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = 0;
                    }
                }
            }
            System.out.println(countCover());
        }
        br.close();
    }

    private static int countCover() {
        int curX = -1, curY = -1;
        // 왼쪽 위부터 시작해서 비어있는 블록 추적
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 0) {
                    curX = j;
                    curY = i;
                    break;
                }
            }
            if (curX != -1) {
                break;
            }
        }
        // Base condition: 모든 블록을 채웠다.
        if (curX == -1) {
            return 1;
        }

        int ret = 0;
        for (int type = 0; type < 4; type++) {
            // 패턴에 맞게 채워본다. 채울 수 있으면 true
            if (cover(type, curX, curY, 1)) {
                ret += countCover();
            }
            // 채운 블록을 원래대로 돌린다.
            cover(type, curX, curY, -1);
        }
        return ret;
    }

    private static boolean cover(int type, int x, int y, int value) {
        boolean flag = true;
        for (int i = 0; i < 3; i++) {
            int nx = x + coverType[type][i][0];
            int ny = y + coverType[type][i][1];
            if (nx < 0 || nx >= board[0].length || ny < 0 || ny >= board.length) {
                flag = false;
            } else if ((board[ny][nx] += value) > 1) {
                flag = false;
            }
        }
        return flag;
    }
}

/*
Testcase 01
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
 */
