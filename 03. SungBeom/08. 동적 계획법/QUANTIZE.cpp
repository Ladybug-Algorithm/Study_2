#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;

// A[]: 양자화해야 할 수열, 정렬한 상태
// pSum[]: A[]의 부분합을 저장한다. pSum[i]는 A[0] .. A[i]의 합
// pSqSum[]: A[] 제곱의 부분합을 저장한다. pSqSum[i]는 A[0]^2 .. A[i]^2의 합
int n;
int A[101], pSum[101], pSqSum[101];

// A를 정렬하고 각 부분합을 계산한다.
void precalc()
{
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];

	for (int i = 1; i < n; ++i)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

// A[lo] .. A[hi] 구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산한다.
int minError(int lo, int hi)
{
	// 부분합을 이용해 A[lo]~A[hi]까지의 합을 구한다.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	// 평균을 반올림한 값으로 이 수들을 표현한다.
	int m = int(0.5 + (double)sum / (hi - lo + 1));

	// sum(A[i]-m)^2를 전개한 결과를 부분 합으로 표현
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);

	return ret;
}

int cache[101][11];

int quantize(int from, int parts)
{
	// 기저 사례: 모든 숫자를 다 양자화했을 때
	if (from == n) return 0;

	// 기저 사례: 숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰 값을 반환한다.
	if (parts == 0) return INF;

	int &ret = cache[from][parts];
	if (ret != -1) return ret;

	ret = INF;
	// 조각의 길이를 변화시켜 가며 최소치를 찾는다.
	for (int partSize = 1; from + partSize <= n; ++partSize)
		ret = min(ret, minError(from, from + partSize - 1) +
			quantize(from + partSize, parts - 1));

	return ret;
}

int main(void)
{
	int C;
	cin >> C;
	
	while (C--)
	{
		int parts;
		cin >> n >> parts;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= parts; j++)
				cache[i][j] = -1;

		for (int i = 0; i < n; i++)
			cin >> A[i];

		precalc();
		
		cout << quantize(0, parts) << '\n';
	}

	system("pause");
	return 0;
}