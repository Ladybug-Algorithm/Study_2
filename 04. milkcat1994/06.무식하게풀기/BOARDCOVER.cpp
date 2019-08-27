/*
code : https://algospot.com/judge/problem/read/BOARDCOVER
H*W 크기의 게임판이 있습니다. 게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데
이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다.
이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나,
게임판 밖으로 나가서는 안 됩니다.
위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.

게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.

입력의 첫 줄에는 테스트 케이스의 수 C (C <= 30) 가 주어집니다.
각 테스트 케이스의 첫 줄에는 2개의 정수 H, W (1 <= H,W <= 20) 가 주어집니다.
다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다.
# 은 검은 칸, . 는 흰 칸을 나타냅니다.
입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.
*/

/*
예제 입력
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

예제 출력
0
2
1514
*/

/*
가장위, 가장 왼쪽을 기준으로 잡을 것
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
	//true일 경우 채워넣기, false일 경우 지우기.
	for (int i = 0; i < 3; i++) {
		vec.at(y + dy[direction][i]).at(x + dx[direction][i]) = type;
	}
}

int boardCover(vector<vector<bool>>& vec) {
	//tempx : width, tempy : height
	int tempx = -1, tempy;
	//가장 처음 빈자리 찾기
	for (int i = 0; i < th; i++) {
		for (int j = 0; j < tw; j++)
			//빈자리가 있다면 이쪽부터 채운다.
			if (!vec.at(i).at(j)) {
				tempx = j; tempy = i;
				break;
			}
		if (tempx != -1) break;
	}
	//빈자리가 없다면 다 채운 것이므로 1반환
	if (tempx == -1) return 1;

	int res = 0;

	for (int i = 0; i < 4; i++) {
		//해당 방향이 비어있는지 확인(false인지), 비어있다면 채우고 boardCover진행
		//3군데가 비어있다면 해당 블럭 씌우기
		//tempy + dy가 범위를 벋어나서는 안 됨
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
				//3칸 다 볼 때까지 실행 하기 위한 continue
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
				//벽일 경우 true
				if (tempChar == '#')
					tile.at(i).push_back(true);
				else
					tile.at(i).push_back(false);
			}
		}
		//게임판 덮기 실행
		cout << boardCover(tile) << endl;

		//tile 모두 삭제
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