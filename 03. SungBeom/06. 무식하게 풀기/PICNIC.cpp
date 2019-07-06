#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];

// taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
int countPairings(bool taken[10])
{
	// ���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; ++i)
		if (!taken[i])
		{
			firstFree = i;
			break;
		}

	// ���� ���: ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
	if (firstFree == -1) return 1;
	int ret = 0;

	// �� �л��� ¦���� �л��� �����Ѵ�.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		int m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				areFriends[i][j] = false;

		while (m--)
		{
			int studentA, studentB;
			cin >> studentA >> studentB;

			areFriends[studentA][studentB] = true;
			areFriends[studentB][studentA] = true;
		}

		bool taken[10];

		for (int i = 0; i < 10; i++)
			taken[i] = false;

		cout << countPairings(taken) << '\n';
	}

	return 0;
}