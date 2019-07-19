#include <iostream>
#include <algorithm>
using namespace std;

int n, triangle[100][100];
int cache[100][100];

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

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cache[i][j] = -1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];

		cout << path(0, 0) << '\n';
	}

	system("pause");
	return 0;
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int path[100][100];
//int cost[100][100];
//int ans;
//
//int next(int x, int y)
//{
//	if (x == 0 && y == 0) return ans + cost[0][0];
//	
//	if (x < y) return ans;
//
//	return max(next(x - 1, y), next(x - 1, y - 1));
//}
//
//int main(void)
//{
//	int C;
//	cin >> C;
//
//	while (C--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j <= i; j++)
//				cost[i][j] = -1;
//		ans = 0;
//
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j <= i; j++)
//				cin >> cost[i][j];
//
//		cout << next(n - 1, n - 1) << '\n';
//	}
//
//	system("pause");
//	return 0;
//}