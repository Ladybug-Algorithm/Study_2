package chap07.quadtree;

import java.util.Scanner;

/**
 * Input: 압축된 QuadTree
 * Output: 상하가 뒤집힌 QuadTree
 */
public class Main {
    private static final Scanner sc = new Scanner(System.in);
    private static int pointer; // iterator 역할

    public static void main(String[] args) {
        int c = Integer.parseInt(sc.nextLine());
        while (c-- > 0) {
            pointer = 0;
            String quadTree = sc.nextLine();
            System.out.println(reverse(quadTree));
        }
        sc.close();
    }

    /**
     * 각 칸을 뒤집은 다음, 3, 4, 1, 2 순서대로 출력하면 전체를 뒤집은 것과 같다.
     */
    private static String reverse(String quadTree) {
        char c = quadTree.charAt(pointer++);

        if (c != 'x') {
            return c + "";
        }
        String upperLeft = reverse(quadTree);
        String upperRight = reverse(quadTree);
        String lowerLeft = reverse(quadTree);
        String lowerRight = reverse(quadTree);

        return String.format("x%s%s%s%s", lowerLeft, lowerRight, upperLeft, upperRight);
    }
}
