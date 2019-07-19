#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;
string N;

// N[a, b] ������ ���̵��� ��ȯ�Ѵ�.
int classify(int a, int b)
{
	// ���� ������ �����´�.
	string M = N.substr(a, b - a + 1);

	// ù ���ڸ����� �̷���� ���ڿ��� ������ ���̵��� 1
	if (M == string(M.size(), M[0])) return 1;

	// ������������ �˻��Ѵ�.
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;

	// ���������̰� ������ 1 Ȥ�� -1�̸� ���̵��� 2
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;

	// �� ���� ������ �����ϴ��� Ȯ���Ѵ�.
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;

	if (alternating) return 4;	// �� ���� ������ �����ϸ� ���̵��� 4
	if (progressive) return 5;	// ������ 1 �ƴ� ���������� ���̵��� 5
	return 10;					// �� �ܴ� ��� ���̵� 10
}

int cache[10002];

// ���� N[begin..]�� �ܿ�� ��� �� ���̵��� �ּ� ���� ����Ѵ�.
int memorize(int begin)
{
	// ���� ���: ������ ���� �������� ���
	if (begin == N.size()) return 0;

	// �޸������̼�
	int &ret = cache[begin];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; ++L)
		if (begin + L <= N.size())
			ret = min(ret, memorize(begin + L) +
				classify(begin, begin + L - 1));
	
	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		cin >> N;
		for (int i = 0; i < N.size(); i++)
			cache[i] = -1;

		cout << memorize(0) << '\n';
	}

	system("pause");
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string num;
//
//int difficulty(int index)
//{
//	// ���̰� ���� ������ return
//
//	// first, second, third�� �ش��ϴ� ���̵� �Ǵ�
//	int first = 0, second = 0, third = 0;
//
//	int firstD = difficulty(index + 3) + first;
//	int secondD = difficulty(index + 4) + second;
//	int thirdD = difficulty(index + 5) + third;
//
//	return firstD < secondD ? (firstD < thirdD ? firstD : thirdD) : (secondD < thirdD ? secondD : thirdD);
//}
//
//int main(void)
//{
//	int C;
//	cin >> C;
//
//	while (C--)
//	{
//		cin >> num;
//
//		cout << difficulty(0) << '\n';
//	}
//
//	return 0;
//}