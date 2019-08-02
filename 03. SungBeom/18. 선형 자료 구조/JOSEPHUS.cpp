#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		int N, K;
		cin >> N >> K;

		list<int> people;
		for (int i = 0; i < N; i++)
			people.push_back(i);

		int death = 0;
		while (people.size() > 2)
		{
			list<int>::iterator next = people.begin();
			for (int i = 0; i < death; i++)
				next++;

			death += (K - 1);
			death %= (N-- - 1);

			people.remove(*next);
		}

		cout << people.front() + 1 << " " << people.back() + 1 << '\n';
	}

	return 0;
}