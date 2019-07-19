#include <iostream>
#include <vector>
using namespace std;

int n, board[100][100];
int cache[100][100];

int jump(int y, int x)
{
	// ���� ���: ������ ���� ��� ���
	if (y >= n || x >= n) return 0;

	// ���� ���: ������ ĭ�� ������ ���
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