/*
문제 : https://algospot.com/judge/problem/read/FENCE
너비가 같은 N개의 나무 판자를 붙여 세운 울타리가 있습니다.
시간이 지남에 따라 판자들이 부러지거나 망가져 높이가 다 달라진 관계로
울타리를 통째로 교체하기로 했습니다.
이 때 버리는 울타리의 일부를 직사각형으로 잘라내 재활용하고 싶습니다.
그림 (b)는 (a)의 울타리에서 잘라낼 수 있는 많은 직사각형 중 가장 넓은 직사각형을 보여줍니다.
울타리를 구성하는 각 판자의 높이가 주어질 때,
잘라낼 수 있는 직사각형의 최대 크기를 계산하는 프로그램을 작성하세요.
단 (c)처럼 직사각형을 비스듬히 잘라낼 수는 없습니다.

판자의 너비는 모두 1이라고 가정합니다.

입력
첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다.
각 테스트 케이스의 첫 줄에는 판자의 수 N (1≤N≤20000)이 주어집니다.
그 다음 줄에는 N개의 정수로 왼쪽부터 각 판자의 높이가 순서대로 주어집니다.
높이는 모두 10,000 이하의 음이 아닌 정수입니다.

출력
각 테스트 케이스당 정수 하나를 한 줄에 출력합니다.
이 정수는 주어진 울타리에서 잘라낼 수 있는 최대 직사각형의 크기를 나타내야 합니다.
*/

/*
예제 입력
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4
1 8 2 2

예제 출력
20
16
8
*/

//이번 것이 올라간 Point 라면 이전 Point를 선택하여 해당 높이에서 가질 수 있는
//최대 넓이를 반환 하는 함수 호출.
//함수 내에서 전역 Result로 저장하기 
//위 내용 반복 한 뒤 최대 값 출력.

/*
처음 2만은 확정 확인
최대높이까지 계속 증가하는 그래프의 형태가 두번 반복이 된다면
최악의 경우의 수 1만개의 Point가 저장됨 and 해당 1만개의 Point를
fecnce의 size만큼 2만번 반복
판자의 수 : N
N+ (N/2) * N -> N + N^2 ?
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> fence;
set<int> targetNum;

//최대 넓이 반환할 것
int findMaxArea(int num) {
	int tempResult = 0, maxArea = 0;

	//모든 값 확인
	for (int i = 0; i < fence.size(); i++) {
		//Point값이 높이보다 작다면 넓이에 더하기
		if (num <= fence[i]) {
			tempResult += num;
		}
		//높이보다 높다면 넓이로 더해주지 못함.
		//지금보다 큰 넓이를 구했다면 갱신
		else {
			if (maxArea < tempResult)
				maxArea = tempResult;
			tempResult = 0;
		}
	}
	return maxArea;
}

int findPoint() {
	int exNum = fence[0];

	for (int i = 1; i < fence.size(); i++) {
		//이번 숫자가 올라온 Point라면 실행
		if (exNum <= fence[i]) {
			exNum = fence[i - 1];
			//set을 이용하여 확인할 숫자를 저장한다.
			targetNum.insert(exNum);
		}
	}

	//저장 해둔 높이를 이용하여 최대 넓이 구하기
	int result=0;
	set<int>::iterator iter;
	for (iter = targetNum.begin(); iter != targetNum.end(); ++iter) {
		int tempResult = findMaxArea(*iter);
		if (result < tempResult)
			result = tempResult;
	}

	return result;
}

int main() {
	int roof, tempNum, result;

	cin >> roof;
	while (roof--) {
		int legnth;
		cin >> legnth;
		for (int i = 0; legnth > i; i++) {
			cin >> tempNum;
			fence.push_back(tempNum);
		}
		result = findPoint();
		cout << result << endl;
		fence.clear();
	}
	return 0;
}