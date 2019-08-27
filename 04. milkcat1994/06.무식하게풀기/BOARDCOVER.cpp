/*
code : https://algospot.com/judge/problem/read/BOARDCOVER
H*W ũ���� �������� �ֽ��ϴ�. �������� ���� ĭ�� �� ĭ���� ������ ���� ����� �ϰ� �ִµ�
�� �� ��� �� ĭ�� 3ĭ¥�� L�� ����� ������� ���� �ͽ��ϴ�.
�� �� ��ϵ��� �����Ӱ� ȸ���ؼ� ���� �� ������, ���� ��ġ�ų�, ���� ĭ�� ���ų�,
������ ������ �������� �� �˴ϴ�.
�� �׸��� �� �����ǰ� �̸� ���� ����� �����ݴϴ�.

�������� �־��� �� �̸� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 30) �� �־����ϴ�.
�� �׽�Ʈ ���̽��� ù �ٿ��� 2���� ���� H, W (1 <= H,W <= 20) �� �־����ϴ�.
���� H �ٿ� �� W ���ڷ� �������� ����� �־����ϴ�.
# �� ���� ĭ, . �� �� ĭ�� ��Ÿ���ϴ�.
�Է¿� �־����� �����ǿ� �ִ� �� ĭ�� ���� 50 �� ���� �ʽ��ϴ�.
*/

/*
���� �Է�
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

���� ���
0
2
1514
*/

/*
������, ���� ������ �������� ���� ��
dx, dy
1. 0,0  0, 1   1, 1
2. 0,0  1, 0   0, 1
3. 0,0  1, 0   1, 1
4. 0,0  0, 1  -1, 1
*/

#include <iostream>
#include <vector>

using namespace std;
int tw, th;

int dx[4][3] = {
	{ 0,  0,  1 },
	{ 0,  1,  0 },
	{ 0,  1,  1 },
	{ 0,  0, -1 },
};

int dy[4][3] = {
	{ 0,  1,  1 },
	{ 0,  0,  1 },
	{ 0,  0,  1 },
	{ 0,  1,  1 },
};
void draw(const vector<vector<bool>>& vec) {
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec.at(0).size(); j++) {
			if (vec.at(i).at(j))
				cout << '#';
			else
				cout << '.';
		}
		cout << endl;
	}
}
void set(vector<vector<bool>>& vec, int x, int y, int direction, bool type) {
	//true�� ��� ä���ֱ�, false�� ��� �����.
	for (int i = 0; i < 3; i++) {
		vec.at(y + dy[direction][i]).at(x + dx[direction][i]) = type;
	}
}

int boardCover(vector<vector<bool>>& vec) {
	//tempx : width, tempy : height
	int tempx = -1, tempy;
	//���� ó�� ���ڸ� ã��
	for (int i = 0; i < th; i++) {
		for (int j = 0; j < tw; j++)
			//���ڸ��� �ִٸ� ���ʺ��� ä���.
			if (!vec.at(i).at(j)) {
				tempx = j; tempy = i;
				break;
			}
		if (tempx != -1) break;
	}
	//���ڸ��� ���ٸ� �� ä�� ���̹Ƿ� 1��ȯ
	if (tempx == -1) return 1;

	int res = 0;

	for (int i = 0; i < 4; i++) {
		//�ش� ������ ����ִ��� Ȯ��(false����), ����ִٸ� ä��� boardCover����
		//3������ ����ִٸ� �ش� �� �����
		//tempy + dy�� ������ ������� �� ��
		for (int j = 0; j < 3; j++) {
			const int tx = tempx + dx[i][j];
			const int ty = tempy + dy[i][j];

			if (0 <= ty && ty < vec.size() &&
				0 <= tx && tx < vec.at(0).size() &&
				!vec.at(ty).at(tx)) {
				if (j == 2) {
					set(vec, tempx, tempy, i, true);
					//cout << "First draw" << endl;
					//draw(vec);
					res += boardCover(vec);
					set(vec, tempx, tempy, i, false);
					//cout << "Second draw" << endl;
					//draw(vec);
					break;
				}
				//3ĭ �� �� ������ ���� �ϱ� ���� continue
				continue;
			}
			break;
		}
	}

	return res;
}

int main() {
	int roof;
	cin >> roof;

	vector<vector<bool>> tile;
	char tempChar;
	while (roof--) {
		cin >> th >> tw;
		for (int i = 0; i < th; i++) {
			tile.push_back(vector<bool>());
			for (int j = 0; j < tw; j++) {
				cin >> tempChar;
				//���� ��� true
				if (tempChar == '#')
					tile.at(i).push_back(true);
				else
					tile.at(i).push_back(false);
			}
		}
		//������ ���� ����
		cout << boardCover(tile) << endl;

		//tile ��� ����
//		for each (vector<bool> obj in tile)
//			obj.clear();
//		tile.clear();
		const int temp = tile.size();
		for (int i = 0; i < temp; i++)
			tile.at(i).clear();
		tile.clear();
	}
	return 0;
}