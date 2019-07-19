#include <iostream>
using namespace std;

const int MOD = 10 * 1000 * 1000;
int cache[101][101];

// n���� ���簢������ �̷������, �� �� �����ٿ� first���� ���簢���� �����ϴ� �������̳��� ���� ��ȯ�Ѵ�.
int poly(int n, int first)
{
	// ���� ���: n == first
	if (n == first) return 1;

	// �޸������̼�
	int &ret = cache[n][first];
	if (ret != -1) return ret;

	ret = 0;
	for (int second = 1; second <= n - first; ++second)
	{
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}

	return ret;
}

int main(void)
{
	int C;
	cin >> C;
	
	while (C--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cache[i][j] = -1;

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += poly(n, i);
			ans %= MOD;
		}

		cout << ans << '\n';
	}

	system("pause");
	return 0;
}