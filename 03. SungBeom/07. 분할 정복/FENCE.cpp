#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �� ������ ���̸� �����ϴ� �迭
vector<int> h;

// h[left..right] �������� ã�Ƴ� �� �ִ� ���� ū �簢���� ���̸� ��ȯ�Ѵ�.
int solve(int left, int right)
{
	// ���� ���: ���ڰ� �ϳ��ۿ� ���� ���
	if (left == right) return h[left];

	// [left, mid], [mid + 1, right]�� �� �������� ������ �����Ѵ�.
	int mid = (left + right) / 2;
	// ������ ������ ��������
	int ret = max(solve(left, mid), solve(mid + 1, right));

	// �κ� ���� 3: �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	// [mid, mid + 1]�� �����ϴ� �ʺ� 2�� �簢���� ����Ѵ�.
	ret = max(ret, height * 2);

	// �簢���� �Է� ��ü�� ���� ������ Ȯ���� ������.
	while (left < lo || hi < right)
	{
		// �׻� ���̰� �� ���� ������ Ȯ���Ѵ�.
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{
			++hi;
			height = min(height, h[hi]);
		}
		else
		{
			--lo;
			height = min(height, h[lo]);
		}

		// Ȯ���� �� �簢���� ����
		ret = max(ret, height*(hi - lo + 1));
	}

	return ret;
}

int main(void)
{
	int C;
	cin >> C;
	h.resize(20000);

	while (C--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> h[i];

		cout << solve(0, N - 1) << '\n';
	}

	system("pause");
	return 0;
}