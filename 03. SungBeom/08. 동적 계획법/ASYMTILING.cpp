#include <iostream>
using namespace std;

const int MOD = 1000000007;
int n, cache[101];

int tiling(int n)
{
	int &ret = cache[n];
	if (ret != 0) return ret;

	return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int main(void)
{
	int C;
	cin >> C;
	cache[0] = 1; cache[1] = 1; cache[2] = 2;

	while (C--)
	{
		cin >> n;

		int ans;
		if (n % 2 == 0) ans = (((tiling(n) - cache[n / 2] + MOD) % MOD) - cache[n / 2 - 1] + MOD) % MOD;
		else ans = (tiling(n) - cache[n / 2] + MOD) % MOD;

		cout << ans << '\n';
	}

	system("pause");
	return 0;
}