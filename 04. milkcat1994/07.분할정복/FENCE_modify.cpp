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
*/

/*
예제 출력
20
16
8
*/

/*
1. 9
2. 좌 : 10, 우 : 12
3. 우 선택
4. 좌 : 15, 우 : 18
5. 우 선택
6. 좌 : 20, 우 : 15
7. 좌 선택
8. 좌 : 5,  우 : 끝임
9. 현재 값이 가장 큼
10. 끝
*/

//기존방식
/*
이번 것이 올라간 Point 라면 이전 Point를 선택하여 해당 높이에서 가질 수 있는
최대 넓이를 반환 하는 함수 호출.
함수 내에서 전역 Result로 저장하기 
위 내용 반복 한 뒤 최대 값 출력.

처음 2만은 확정 확인
최대높이까지 계속 증가하는 그래프의 형태가 두번 반복이 된다면
최악의 경우의 수 1만개의 Point가 저장됨 and 해당 1만개의 Point를
fecnce의 size만큼 2만번 반복
판자의 수 : N
N+ (N/2) * N -> N + N^2 ?
*/

//기존 방식의 문제점
/*
1. 예외가 되는 방식이 있음... (기억이 나지 않음)
2. n^2 + n 의 시간 복잡도가 걸린다.
*/

//개선 방식
/*
Question : 가장 큰 막대 중심 직사각형이 가장 큰 직사각형이 아니라면?...
이것 또한 모든 직사각형을 확인 해야하지 않나?..

Idea : 직사각형을 만들 경우 처음과 끝의 점 사이의 막대들은 직사각형의 높이보다는 크거나 같다.
	   직사각형이 만들어 지는 경우의 수는 가장 긴막대를 이용한 기준선의
	   좌측이거나, 우측이거나, 두 부분을 포함하거나 이다.

Then : 두 부분으로 나누어 선형시간만큼(2N) 계속적으로 확인 하는 것으로 보아
	   Merge Sort가 연상된다. 시간복잡도는 Nlog(N).
	   └>기준선을 중심으로 두 부분을 포함하는 경우
	   기준선을 중심으로 좌,우측

Solve :
1. 두 구간으로 분할 [left, mid], [mid+1, right] 하여 두 구간 중 큰 넓이 저장. 'Result'
   └> 직사각형이 좌측이거나, 우측일 때의 경우.

2. 중심 포함할때의 경우 찾아가기.
   1) mid ~ mid+1의 넓이가 첫 넓이이다.
   2) 위 넓이와 'Result'와의 비교를 통해 큰 것을 'Result'로 갱신

3. 중심을 확장해 나간다.
   1) left~right까지 확장 하되 순서는 좌/우 중 큰 곳으로 확장한다.
   2) **선택한 구간 중 최소높이인 height를 기억하여 계산을 쉽게 만든다. height*Length
*/

#include <iostream>
#include <vector>
//max, min 사용위한 헤더파일
#include <algorithm>
using namespace std;

vector<int> fence;

//최대 넓이 반환할 것
//작성시 fence[mid]와 mid 잘 구분해서 넣어주어야 함.
int findMaxArea(int left, int right) {
	//만약 left와 right가 같다면 해당 index의 값 반환(해당 index의 값이 높이이자 넓이)
	if (left == right) {
		return fence[left];
	}

	//구간이 존재할 경우 반으로 나누어 계산한다.
	int mid = (left + right) / 2;
	//좌,우 측중 가장 큰 값 저장.
	int result = max(findMaxArea(left, mid), findMaxArea(mid + 1, right));

	//중심을 기준으로 삼은 좌,우측 구간
	//계산 간략화 위한 높이 저장
	int cLeft, cRight, height;
	cLeft = mid;	cRight = mid + 1;
	height = min(fence[cLeft], fence[cRight]);

	//중심을 포함하는 기본 넓이와 저장된 큰 값을 비교하여 갱신한다.
	result = max(result, height*2);
	
	//left, right까지 넓혀 가며 높이가 높은 곳으로 확장해나간다.
	while (left < cLeft || cRight < right) {
		//우측으로 늘릴 수 있을 때
		if (cRight + 1 <= right && (cLeft == left || fence[cLeft-1] <= fence[cRight+1]) ) {
			//우측 으로 확장 이후 해당 위치의 높이와 기존 높이 중 낮은 것 선택
			cRight += 1;
			height = min(height, fence[cRight]);
		}
		//우측으로 공간이 있고, 좌측으로 공간이 있으며, 좌측의 높이가 더 높을 경우
		else {
			cLeft -= 1;
			height = min(height, fence[cLeft]);
		}

		//넓이 더 큰것으로 갱신
		result = max(result, height*(cRight - cLeft + 1));

		//left, right 둘다 동시에 빼면 안 된다.
		//why? 더 큰 방향으로 이동해야 하기 때문
//		cLeft -= 1; cRight += 1;
//		cLeft = max(cLeft, left);	cRight = min(cRight, right);
}
	return result;
}

int main() {
	int roof, tempNum;

	cin >> roof;
	while (roof--) {
		int legnth;
		cin >> legnth;
		for (int i = 0; i < legnth; ++i) {
			cin >> tempNum;
			fence.push_back(tempNum);
		}
		cout << findMaxArea(0, fence.size()-1) << endl;
		fence.clear();
	}
	return 0;
}