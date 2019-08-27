/*
code : https://algospot.com/judge/problem/read/PICNIC
안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다.
원석 선생님은 소풍 때 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다.
그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에,
항상 서로 친구인 학생들끼리만 짝을 지어야 합니다.
각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝 지을 수 있는
방법의 수를 계산하는 프로그램을 작성하세요. 짝이 되는 학생들이 일부만
다르더라도 다른 방법이라고 봅니다. 예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.
(태연, 제시카) (써니, 티파니) (효연, 유리)
(태연, 제시카) (써니, 유리) (효연, 티파니)

1초 내에 실행 되어야 하고 64MB 이하 메모리 사용
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다.

각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10) 과
친구 쌍의 수 m (0 <= m <= n*(n-1)/2) 이 주어집니다.
그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다.
번호는 모두 0 부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다.
학생들의 수는 짝수입니다.
*/

/*
입력
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

(0, 1) (1, 2) (2, 3) (3, 0) (0, 2) (1, 3)
출력
1
3
4
*/

//0부터 10까지 순서대로 돌면서 누구와 짝을 지을 수 있는지 확인,
//지을 수 있다면 그사람은 선택 안되게 토글 해둘 것.
//위의 경우 중복되는 경우가 생김 0,1 2,3 / 2,3 0,1 순으로 중복 선택됨
//위 경우를 없애기 위해 선택되지 않은 수 중 가장 작은 수부터 연결 해주면 됨.
#include <iostream>
using namespace std;

//학생의 연결 관계 배열
bool connectArr[10][10] = {};
//학생 수
int snum=0;

int countConnect(bool selected[]) {
	int res = 0;
	int startPoint = -1;

	//선택 되있지 않다면 해당 학생을 먼저 확인한다.
	for (int i = 0; i < snum; i++)
		if (!selected[i]) {
			startPoint = i;
			break;
		}

	//더 이상 볼 필요가 없다면 1을 반환 해 총 갯수에서 1을 더해준다.
	if (startPoint < 0)
		return 1;

	//선택되지 않은 수 중 가장 작은 수의 행(startPoint)만 확인 하여 누구와 연결되있는지 확인.
	for (int i = startPoint+1; i < snum; i++)
		//선택되지 않은 짝이라면 짝 찾기
		if (!selected[startPoint] && !selected[i] && connectArr[startPoint][i]) {
			selected[startPoint] = true; selected[i] = true;
			res += countConnect(selected);
			selected[startPoint] = false; selected[i] = false;
		}

	return res;
}


int main() {
	//테케 반복 횟수, 짝의 수
	int roof, cnum;
	//짝의 첫째, 두째
	int tempf, tempe;
	//학생 선택 확인 배열
	cin >> roof;

	while (roof--) {
		//학생이 선택되었는지 확인하는 배열
		bool isSelectedStudent[10] = {};
		cin >> snum >> cnum;
		//짝궁 초기화
		while (cnum--) {
			cin >> tempf >> tempe;
			if(tempf<tempe)
				connectArr[tempf][tempe] = true;
			else
				connectArr[tempe][tempf] = true;
		}
		//연결 갯수 출력
		cout << countConnect(isSelectedStudent) << endl;

		//연결 상태 초기화
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				connectArr[i][j] = false;
	}
	return 0;
}