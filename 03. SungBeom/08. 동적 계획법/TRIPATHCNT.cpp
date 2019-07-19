#include <iostream>
#include <algorithm>
using namespace std;

int n, triangle[100][100];
int cache[100][100];
int countCache[100][100];

// (y, x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int path(int y, int x)
{
	// 기저 사례
	if (y == n - 1) return triangle[y][x];

	// 메모이제이션
	int &ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

//(y, x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환한다.
int count(int y, int x)
{
	// 기저 사례: 맨 아래줄에 도달한 경우
	if (y == n - 1) return 1;

	// 메모이제이션
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