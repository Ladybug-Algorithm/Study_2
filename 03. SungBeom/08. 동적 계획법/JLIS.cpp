#include <iostream>
#include <algorithm>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

// min(A[indexA], B[indexB]), max(A[indexA], B[indexB])�� �����ϴ�
// ��ģ ���� �κ� ������ �ִ� ���̸� ��ȯ�Ѵ�.
// �� indexA == indexB == -1 Ȥ�� A[indexA] != B[indexB]��� �����Ѵ�.
int jlis(int indexA, int indexB)
{
	// �޸������̼�
	int &ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	// A[indexA], B[indexB]�� �̹� �����ϹǷ� 2���� �׻� �ִ�.
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	// ���� ���Ҹ� ã�´�.
	for (int nextA = indexA + 1; nextA < n; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	for (int nextB = indexB + 1; nextB < m; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> n >> m;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				cache[i][j] = -1;

		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i<m; i++)
			cin >> B[i];

		cout << jlis(-1, -1) - 2 << '\n';
	}

	system("pause");
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int ns[100], ms[100];
//
//int main(void)
//{
//	int C;
//	cin >> C;
//
//	while (C--)
//	{
//		int n, m;
//		cin >> n >> m;
//
//		for (int i = 0; i < n; i++)
//			cin >> ns[i];
//		for(int i=0; i<m; i++)
//			cin >> ms[i];
//	}
//
//	return 0;
//}