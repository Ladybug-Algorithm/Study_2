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
#include <iostream>
#include <vector>

using namespace std;
vector<char> quadtree;
vector<char> result;

//앞, 뒤 로 분할, 뒤를 먼저 확인하기.
//뒤 출력 시 x를 먼저 출력
int rotateQuadTree(int start, int end) {
	//더 이상 볼 필요 없을 떄
	if (end == start) {
		result.push_back(quadtree[start]);
		return 0;
	}
	else if (end-start == 1) {
		result.push_back(quadtree[start]);
		result.push_back(quadtree[end]);
		return 0;
	}

	//x가 나올때 까지 반복해서 찾기, 나오지 않는다면 result에 추가.
	//x범위 앞에 나오는 w,b 의 경우 이전에 이미 출력
	for (int i = start; i < quadtree.size(); i++) {
		if (quadtree[i] == 'x')
			break;
		result.push_back(quadtree[i]);
		start += 1;
	}

	//기본 끝 위치는 x다음 2개까지
	int sPointE = start + 2;

	//앞 분할 지점 찾기
	//당연히 맨앞은 x이므로 볼 필요 x
	for (int i = start+1; sPointE >= i; i++) {
		if (quadtree[i] == 'x') {
			sPointE += 4;
		}
	}

	int ePointE = sPointE + 2;
	//뒤 분할 지점
	for (int i = sPointE + 1; ePointE >= i; i++) {
		if (quadtree[i] == 'x') {
			ePointE += 4;
		}
	}

	//뒤
	result.push_back('x');
	rotateQuadTree(sPointE+1, ePointE);

	//앞
	rotateQuadTree(start+1, sPointE);
	//x범위 뒤에 나오는 부분이 있을테니 지금확인

	if (ePointE != end) {
		rotateQuadTree(ePointE + 1, end);
	}
	return 0;
}

int main() {
	int roof;
	char tempC;

	cin >> roof;
	while (roof--) {
		int length = 1;
		for (int i = 0; length > i; i++) {
			cin >> tempC;
			quadtree.push_back(tempC);
			if (tempC == 'x') {
				length += 4;
			}
		}
		rotateQuadTree(0, quadtree.size()-1);
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
		cout << endl;
		quadtree.clear();
		result.clear();
	}
	return 0;
}