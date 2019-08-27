/*
문제 : https://algospot.com/judge/problem/read/QUADTREE
대량의 좌표 데이터를 메모리 안에 압축해 저장하기 위해 사용하는 여러 기법 중 쿼드 트리(quad tree)란 것이 있습니다. 주어진 공간을 항상 4개로 분할해 재귀적으로 표현하기 때문에 쿼드 트리라는 이름이 붙었는데, 이의 유명한 사용처 중 하나는 검은 색과 흰 색밖에 없는 흑백 그림을 압축해 표현하는 것입니다. 쿼드 트리는 2N × 2N 크기의 흑백 그림을 다음과 같은 과정을 거쳐 문자열로 압축합니다.

이 그림의 모든 픽셀이 검은 색일 경우 이 그림의 쿼드 트리 압축 결과는 그림의 크기에 관계없이 b가 됩니다.
이 그림의 모든 픽셀이 흰 색일 경우 이 그림의 쿼드 트리 압축 결과는 그림의 크기에 관계없이 w가 됩니다.
모든 픽셀이 같은 색이 아니라면, 쿼드 트리는 이 그림을 가로 세로로 각각 2등분해 4개의 조각으로 쪼갠 뒤 각각을 쿼드 트리 압축합니다. 이때 전체 그림의 압축 결과는 x(왼쪽 위 부분의 압축 결과)(오른쪽 위 부분의 압축 결과)(왼쪽 아래 부분의 압축 결과)(오른쪽 아래 부분의 압축 결과)가 됩니다. 예를 들어 그림 (a)의 왼쪽 위 4분면은 xwwwb로 압축됩니다.
그림 (a)와 그림 (b)는 16×16 크기의 예제 그림을 쿼드 트리가 어떻게 분할해 압축하는지를 보여줍니다. 이때 전체 그림의 압축 결과는 xxwww bxwxw bbbww xxxww bbbww wwbb가 됩니다.

쿼드 트리로 압축된 흑백 그림이 주어졌을 때, 이 그림을 상하로 뒤집은 그림 을 쿼드 트리 압축해서 출력하는 프로그램을 작성하세요.

첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다. 그 후 C줄에 하나씩 쿼드 트리로 압축한 그림이 주어집니다. 모든 문자열의 길이는 1,000 이하이며, 원본 그림의 크기는 220 × 220 을 넘지 않습니다.

출력
각 테스트 케이스당 한 줄에 주어진 그림을 상하로 뒤집은 결과를 쿼드 트리 압축해서 출력합니다.

*/

/*
예제 입력
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

예제 출력
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
*/
//x( x(wwwb) x(wx(wbbb)ww) x(x(x(wwbb)bww)wwb) b)

//기존 방식
/*
x는 한 사각형을 묶는 문자이다.
x뒤로는 4가지의 색상이 나와야한다.
색상이 나와야 하는 곳에 x가 나왔을 경우 밖 사각형은 4개의 문자가 아니라 8개의 문자를 가진다.
ex) 1 2 3 4 가 있을 경우
뒤집으면, 3 4 1 2 가 되는 방법을 이용하여 내부를 뒤집는다.
*/

//문제점
/*
방법은 같으나 코드가 너무 복잡하다.
간단히 재귀 방식으로 구현할 수 있음에도 2,3 사이인 분할지점을 찾아 재귀적으로 풀어내었다.
이로 인해 기억해야할 index, pivot의 양이 많다.
bottom-up 방식을 이용하여 간단한 재귀 함수로 작성해보자.
*/

//개선 방식
/*
만일 해당 색상이 x라면 재귀함수 호출 하여 해당 색상으로의 정렬
ex) 1 (a b c d) 3 4 라면
1 (c d a b) 3 4 로 먼저 정렬하고
3 4 1 (c d a b) 로 정렬

String을 Iterator를 이용하여 순차적으로 확인하며
'x'가 나올 경우, 아닌 경우에 대해 조건을 달아 순서를 재정립 해보자.
*/

#include <iostream>
#include <string>

using namespace std;
string mainString;
string::iterator iter;

//'pivot'이라는 임의의 변수가 아닌 String iterator이용해보기.
//xbwxwbbwb
string rotateQuadTree() {
	char tempChar = *iter;
	iter++;

	//'x'가 아니라면 해당 'b', 'w'를 반환한다.
	if (tempChar != 'x')
		return string(1, tempChar);

	//'x'라면 내부 사각형에 대해 재귀 함수 호출
	string upperLeft, upperRight, lowerLeft, lowerRight;
	upperLeft = rotateQuadTree();
	upperRight = rotateQuadTree();
	lowerLeft = rotateQuadTree();
	lowerRight = rotateQuadTree();

	//내부 사각형의 순서 재정립하여 반환
	return string(1, 'x') + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	int roof;

	cin >> roof;
	while (roof--) {
		cin >> mainString;
		iter = mainString.begin();
		cout << rotateQuadTree() << endl;
	}
	return 0;
}