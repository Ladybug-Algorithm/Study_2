/*
5x5 알파벳 격자를 가지고 하는 게임이다.
게임의 목적은 상하좌우/대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는 것입니다.
각 글자들은 대각선으로도 이어질 수 있으며, 한 글자가 두 번 이상 사용될 수도 있습니다.
주어진 칸에서 시작해서 특정 단어를 찾을 수 있는지 확인하는 문제를 풀어보자.

hasWord(y,x,word)=보글 게임판의 (y,x)에서 시작하는 단어 word의 존재 여부를 반환한다.
*/

/*
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
6
PRETTY
GIRL
REPEAT
KARA
PANDORA
GIAZAPX

1
URLPM
XPRET
GIAET
XTNZY
XOQRS
1
PRETTY
*/
#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 5
using namespace std;

char board[MAX_SIZE][MAX_SIZE];
vector<string> result;
int dx[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1,  0, 0,  1, 1, 1};

bool isRange(int x, int y) {
	if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE)
		return false;
}

bool hasWord(int y, int x, const string& word) {
	//해당 위치의 단어가 일치하지 않을 경우 실패
	if (board[y][x] != word[0])
		return false;
	//1글자만 남았을 경우 성공
	if (word.size() == 1)
		return true;
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		//해당 범위 내에 없다면 다음 방향 재설정
		if (!isRange(nx, ny))
			continue;
		//해당 언어를 찾았다면 성공
		if (hasWord(ny, nx, word.substr(1)))
			return true;
	}
	
	//8방향 모두 못찾았다면 실패
	return false;
}

void main() {
	int boardRoof, tcnum;
	string tempStr;
	cin >> boardRoof;

	//board의 갯수 만큼 테스트케이스를 확인
	while (boardRoof--) {
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				cin >> board[i][j];
		//테스트케이스 횟수 입력
		cin >> tcnum;
		while (tcnum--) {
			//확인 할 단어 입력
			cin >> tempStr;
			for (int i = 0; i < MAX_SIZE; i++)
				for (int j = 0; j < MAX_SIZE; j++) {
					//해당 단어를 찾았을 경우
					if (hasWord(i, j, tempStr)) {
						i = MAX_SIZE; j = MAX_SIZE;
						result.push_back(tempStr + string(" YES"));
					}
					else if (i == MAX_SIZE - 1 && j == MAX_SIZE - 1) {
						result.push_back(tempStr + string(" NO"));
					}
				}
		}
	}

	for each (string var in result)
		cout << var << endl;
}