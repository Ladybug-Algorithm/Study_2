#include <iostream>
#include <string>
using namespace std;

// -1�� ���� ���� ������ �ʾ����� �ǹ��Ѵ�.
// 1�� �ش� �Էµ��� ���� �������� �ǹ��Ѵ�.
// 0�� �ش� �Էµ��� ���� �������� ������ �ǹ��Ѵ�.
int cache[101][101];
//���ϰ� ���ڿ�
string W, S;

bool matchMemoized(int w, int s)
{
	// �޸������̼�
	int &ret = cache[w][s];

	if (ret != -1) return ret;

	// W[w]�� S[s]�� ���糪����.
	while (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized(w + 1, s + 1);
	/*while (w < W.size() && s < S.size() &&
		(W[w] == '?' || W[w] == S[s]))
	{
		++w;
		++s;
	}*/

	// �� �̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	// 2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ��
	if (w == W.size()) return ret = (s == S.size());

	// 4. *�� ������ ���� ���: *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ���Ѵ�.
	if (W[w] == '*')
		if (matchMemoized(w + 1, s) ||
			(s < S.size() && matchMemoized(w, s + 1)))
			return ret = 1;
	/*if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); ++skip)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;*/

	// 3. �� ���� ��쿡�� ��� �������� �ʴ´�.
	return ret = 0;
}

bool match(const string &w, const string &s)
{
	// w[pos]�� s[pos]�� ���糪����.
	int pos = 0;

	while (pos < s.size() && pos < w.size() &&
		(w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	// �� �̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	// 2. ���� ���� �����ؼ� ���� ���: ���ڿ��� ������� ������
	if (pos == w.size())
		return pos == s.size();

	// 4. *�� ������ ���� ���: *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ���Ѵ�.
	if (w[pos] == '*')
		for (int skip = 0; pos + skip <= s.size(); ++skip)
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
	
	// �� ���� ��쿡�� ��� �������� �ʴ´�.
	return false;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		int n;
		cin >> W >> n;

		while (n--)
		{
			cin >> S;
			for (int i = 0; i < W.size(); i++)
				for (int j = 0; j < S.size(); j++)
					cache[i][j] = -1;

			if (match(W, S))
				cout << S << '\n';
		}
	}

	system("pause");
	return 0;
}