#include <iostream>
#include <queue>
using namespace std;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n)
{
	RNG rng;	// 신호값을 생성하는 난수 생성기
	queue<int> range;	// 현재 구간에 들어 있는 숫자들을 저장하는 큐
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		// 구간에 숫자를 추가한다.
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		// 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺀다
		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
		}

		if (rangeSum == k) ret++;
	}

	return ret;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		int K, N;
		cin >> K >> N;

		cout << countRanges(K, N) << '\n';
	}

	return 0;
}