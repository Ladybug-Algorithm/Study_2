#include <iostream>
#include <vector>
using namespace std;

int n, board[100][100];
int cache[100][100];

int jump(int y, int x)
{
	// 기저 사례: 게임판 밖을 벗어난 경우
	if (y >= n || x >= n) return 0;

	// 기저 사례: 마지막 칸에 도착한 경우
	if (y == n - 1 && x == n - 1) return 1;

	int &ret = cache[y][x];
	if (ret != -1) return ret;

	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cache[i][j] = -1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];

		jump(0, 0) ? cout << "YES" : cout << "NO";
		cout << '\n';
	}

	system("pause");
	return 0;
}