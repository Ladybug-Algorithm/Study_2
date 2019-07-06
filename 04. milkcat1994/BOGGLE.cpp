/*
5x5 ���ĺ� ���ڸ� ������ �ϴ� �����̴�.
������ ������ �����¿�/�밢������ ������ ĭ���� ���ڵ��� �̾ �ܾ ã�Ƴ��� ���Դϴ�.
�� ���ڵ��� �밢�����ε� �̾��� �� ������, �� ���ڰ� �� �� �̻� ���� ���� �ֽ��ϴ�.
�־��� ĭ���� �����ؼ� Ư�� �ܾ ã�� �� �ִ��� Ȯ���ϴ� ������ Ǯ���.

hasWord(y,x,word)=���� �������� (y,x)���� �����ϴ� �ܾ� word�� ���� ���θ� ��ȯ�Ѵ�.
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
	//�ش� ��ġ�� �ܾ ��ġ���� ���� ��� ����
	if (board[y][x] != word[0])
		return false;
	//1���ڸ� ������ ��� ����
	if (word.size() == 1)
		return true;
	
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		//�ش� ���� ���� ���ٸ� ���� ���� �缳��
		if (!isRange(nx, ny))
			continue;
		//�ش� �� ã�Ҵٸ� ����
		if (hasWord(ny, nx, word.substr(1)))
			return true;
	}
	
	//8���� ��� ��ã�Ҵٸ� ����
	return false;
}

void main() {
	int boardRoof, tcnum;
	string tempStr;
	cin >> boardRoof;

	//board�� ���� ��ŭ �׽�Ʈ���̽��� Ȯ��
	while (boardRoof--) {
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				cin >> board[i][j];
		//�׽�Ʈ���̽� Ƚ�� �Է�
		cin >> tcnum;
		while (tcnum--) {
			//Ȯ�� �� �ܾ� �Է�
			cin >> tempStr;
			for (int i = 0; i < MAX_SIZE; i++)
				for (int j = 0; j < MAX_SIZE; j++) {
					//�ش� �ܾ ã���� ���
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