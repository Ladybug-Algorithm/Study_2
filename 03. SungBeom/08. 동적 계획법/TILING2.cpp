#include <iostream>
using namespace std;

int n, cache[101];

int tiling(int n)
{
	int &ret = cache[n];
	if (ret != 0) return ret;

	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}

int main(void)
{
	int C;
	cin >> C;
	cache[1] = 1; cache[2] = 2;

	while (C--)
	{
		cin >> n;

		cout << tiling(n) << '\n';
	}

	system("pause");
	return 0;
}