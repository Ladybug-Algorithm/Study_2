#include <iostream>
#include <algorithm>
using namespace std;

int n, triangle[100][100];
int cache[100][100];
int countCache[100][100];

// (y, x) ��ġ���� �� �Ʒ��ٱ��� �������鼭 ���� �� �ִ� �ִ� ����� ���� ��ȯ�Ѵ�.
int path(int y, int x)
{
	// ���� ���
	if (y == n - 1) return triangle[y][x];

	// �޸������̼�
	int &ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

//(y, x)���� �����ؼ� �� �Ʒ��ٱ��� �������� ��� �� �ִ� ����� ������ ��ȯ�Ѵ�.
int count(int y, int x)
{
	// ���� ���: �� �Ʒ��ٿ� ������ ���
	if (y == n - 1) return 1;

	// �޸������̼�
	int &ret = countCache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	if (path(y + 1, x + 1) >= path(y + 1, x)) ret += count(y + 1, x + 1);
	if (path(y + 1, x + 1) <= path(y + 1, x)) ret += count(y + 1, x);
	
	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
			{
				cache[i][j] = -1;
				countCache[i][j] = -1;
			}

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];

		cout << count(0, 0) << '\n';
	}

	system("pause");
	return 0;
}