#include <iostream>
using namespace std;

int n, d, p, q;
double cache[51][101];

// connected[i][j] = ���� i, j�� ����Ǿ� �ֳ� ����
// deg[i] = ���� i�� ����� ������ ����
int connected[51][51], deg[51];

double search(int here, int days)
{
	// ���� ���: 0�� °
	if (days == 0) return (here == p ? 1.0 : 0.0);

	// �޸������̼�
	double &ret = cache[here][days];
	if (ret > -0.5) return ret;

	ret = 0.0;
	for (int there = 0; there < n; ++there)
		if (connected[here][there])
			ret += search(there, days - 1) / deg[there];

	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> n >> d >> p;
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= d; j++)
				cache[i][j] = -1;
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> connected[i][j];
				if (connected[i][j] == 1) temp++;
			}
			deg[i] = temp;
		}

		int t;
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			cin >> q;
			cout << search(q, d) << ' ';
		}
		cout << '\n';
	}

	system("pause");
	return 0;
}