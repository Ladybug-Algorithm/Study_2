/*
--사이트에서 세그멘테이션 오류가 발생하나 이유를 몰라 업로드 진행
문제 : https://algospot.com/judge/problem/read/FANMEETING
가장 멤버가 많은 아이돌 그룹으로 기네스 북에 올라 있는 혼성 팝 그룹 하이퍼시니어가
데뷔 10주년 기념 팬 미팅을 개최했습니다.
팬 미팅의 한 순서로, 멤버들과 참가한 팬들이 포옹을 하는 행사를 갖기로 했습니다.
하이퍼시니어의 멤버들은 우선 무대에 일렬로 섭니다.
팬 미팅에 참가한 M명의 팬들은 줄을 서서 맨 오른쪽 멤버에서부터 시작해 한 명씩 왼쪽으로 움직이며
멤버들과 하나씩 포옹을 합니다. 모든 팬들은 동시에 한 명씩 움직입니다.
아래 그림은 행사 과정의 일부를 보여줍니다.
a~d는 네 명의 하이퍼시니어 멤버들이고,
0~5는 여섯 명의 팬들입니다.

하지만 하이퍼시니어의 남성 멤버들이 남성 팬과 포옹하기가 민망하다고 여겨서,
남성 팬과는 포옹 대신 악수를 하기로 했습니다.
줄을 선 멤버들과 팬들의 성별이 각각 주어질 때 팬 미팅이 진행되는 과정에서
하이퍼시니어의 모든 멤버가 동시에 포옹을 하는 일이 몇 번이나 있는지 계산하는 프로그램을 작성하세요.

입력
첫 줄에 테스트 케이스의 개수 C (C≤20)가 주어집니다.
각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 각각 나타내는 두 줄의 문자열로 구성되어 있습니다.
각 문자열은 왼쪽부터 오른쪽 순서대로 각 사람들의 성별을 나타냅니다.

M은 해당하는 사람이 남자, F는 해당하는 사람이 여자임을 나타냅니다.
멤버의 수와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하입니다.

출력
각 테스트 케이스마다 한 줄에 모든 멤버들이 포옹을 하는 일이 몇 번이나 있는지 출력합니다.
*/

/*
예제 입력
4
FFFMMM
MMMFFF
FFFFF
FFFFFFFFFF
FFFFM
FFFFFMMMMF
MFMFMFFFMMMFMF
MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF

예제 출력
1
6
2
2
*/

//풀이방법 연대기
/*
모든 멤버가 동시에 무언가를 한다면 횟수는 멤버, 팬의 수를 N, M으로 둘 경우
|N-M|+1

이중 모든 멤버가 동시에 포옹을 할경우의 수는
M M F F  =>  M F F  =>  M F
M F M F  =>  F M F  =>  F X

AND연산과 같은 결과를 지님
M = 1, F = 0으로 치환하여 비트와 시프트 연산을 이용하여 결과값이 0이 아닐경우
틀린 결과이다.

문제점 : 비트 길이가 최대 20만으로 저장및 연산이 불가하다.
==> 자릿수가 긴 곱셈을 나누어 할 수 있는 알고리즘이 존재한다. [카라추바 알고리즘]
:: https://sangdo913.tistory.com/22
*/

//카라추바 알고리즘
/*
x,y를 분할한다.
x = x1*B^m + x0
y = y1*B^m + y0
(x0,y0 < B^m)

z2 = x1y1
z1 = x1y0 + x0y1
z0 = x0y0

xy = (x1*B^m + x0)(y1*B^m + y0)
   = z2*B^(2m) + z1*B^m + z0

z1 = (x1y1 + x1y0 + x0y1 + x0y0) - x1y1 - x0y0
   = x1y0 + x0y1
즉, z1 = (x1 + x0)(y1 + y0) - z2 - z0


예::
B = 10 이라하고, m = 2 라 하자. 1234와 5678의 곱을 구하고 싶으면,

12 34 = 12 × 10^2 + 34
56 78 = 56 × 10^2 + 78
z2 = 12 × 56 = 672
z0 = 34 × 78 = 2652
z1 = (12 + 34)(56 + 78) ? z2 ? z0 = 46 × 134 ? 672 ? 2652 = 2840
결과 = z2 × 10^(2×2) + z1 × 10^2 + z0 = 672 × 10000 + 2840 × 100 + 2652 = 7006652

=>z0, z1, z2를 카라츠바 알고리즘 이용하여 구하기.
*/
/*
팬을 멤버의 수만큼 잘라, 비교를 실시한다.
비교의 경우 위의 카라추바 알고리즘 시행.
1. 비교할때 if문 사용 하여 비교
2. 
공통 : 둘중 하나라도 0 or F라면 일치한 경우이다.
*/

/*
N -> 멤버의 수
M -> 팬들의 수
(M-N+1)*N^log3...?  흐음.....
앞의 (M-N+1) => 모두 비교해야되어 꼭 필요한데...
뒤의 N => 카라추파 알고리즘의 N

긴 문자를 뒤집어 세로로 더해지는 값을 확인 시
한번씩 따로 비교하지 않아도 됨을 알 수 있다. <- 책에 적혀있음.

그리하여 N^log3에 근접할 것임.
기저의 경우 떄에 따라 바꾸어도됨
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void add(vector<int>& res, const vector<int>& v, int k) {
	vector<int> tempVec(res.size(),0);
	res.resize(tempVec.size()+v.size() + k, 0);
	for (int i = 0; i < v.size(); ++i) {
		res[i + k] += v[i];
	}
}

void add(vector<int>& m, const vector<int>& f) {
	//add(m1, m0)
	int end = max(m.size(), f.size());

	for (int i = 0; i < end; ++i) {
		m[i] += f[i];
	}
}

void sub(vector<int>& m, const vector<int>& f) {

	int end = max(m.size(), f.size());

	for (int i = 0; i < end; ++i) {
		m[i] -= f[i];
	}
}

//빼기 이후 정상화 작업
void normalize(vector<int>& m) {
	for (int i = 0; i < m.size(); ++i) {
		if (m[i] < 0) {
			m[i + 1] -= abs(m[i]/10) +1;
			m[i] = m[i] % 10 + 10;
		}
		else if(m[i] > 9) {
			m[i + 1] += m[i]/10;
			m[i] = m[i]%10;
		}
	}
}

vector<int> multiply(const vector<int>& m, const vector<int>& f) {
	vector<int> tempResult;
	tempResult.resize(m.size() + f.size() - 1);
	for (int i = 0; i < m.size(); ++i) {
		for(int j = 0 ; j< f.size(); ++j){
			tempResult[i + j] += m[i] * f[j];
		}
	}
	return tempResult;
}

vector<int> karatsuba(const vector<int>& m, const vector<int>& f) {
	//a,b길이 /2 !=0 이라면 나누기
	vector<int> tempResult;
	//하나의 vector이 비어있는경우
	if (m.size() > f.size()) return karatsuba(f, m);
	if (m.empty() || f.empty()) return vector<int>();
	//사이즈가 50 이하라면 일반적인 곱셈으로 계산한다.
	if (f.size() <= 50) {
		return multiply(m, f);
	}

	//절반으로 나누는 대신 m의 경우 f의 절반보다 size가 작을 수도 있으니 고려
	int half = f.size() / 2;
	vector<int> m0(m.begin(), m.begin() + min(half, (int)m.size()));
	vector<int> m1(m.begin() + min(half, (int)m.size()), m.end());
	vector<int> f0(f.begin(), f.begin() + half);
	vector<int> f1(f.begin() + half, f.end());

	vector<int> z2 = karatsuba(m1, f1);
	vector<int> z0 = karatsuba(m0, f0);

	add(m1, m0);
	add(f1, f0);

	vector<int> z1 = karatsuba(m1, f1);
	sub(z1, z2);
	sub(z1, z0);
	normalize(z1);

	//half를 m,f따로 잡는것이 아닌 하나로 통일 해야한다.
	//z2*10^(2*half) + z1*10^(half) + z0;
	add(tempResult, z2, half + half);
	add(tempResult, z1, half);
	add(tempResult, z0);
	normalize(tempResult);

	return tempResult;
}

int solve(const string& member, const string& fan) {
	int result=0;
	int mSize = member.size(), fSize = fan.size();
	vector<int> M(mSize), F(fSize);
	vector<int> resultV;
	//M을 거꾸로 저장
	for (int i = 0; i<mSize; ++i) {
		member[mSize-i-1] == 'M' ? M[i] = 1 : M[i] = 0;
	}

	for (int i = 0; i<fSize; ++i) {
		fan[i] == 'M' ? F[i] = 1 : F[i] = 0;
	}
	resultV = karatsuba(M, F);

	//확인할 범위를 지정해주어야 한다.
	//확인 가능한 횟수
	int length = fSize - mSize + 1;
	//확인 시작할 Point
	int sp = fSize - length;
	//sp = msize+1
	for (int i = sp; i < sp+length; ++i) {
		if (resultV[i] == 0)
			result++;
	}
	return result;
}

int main() {
	int roof;
	string member, fan;

	cin >> roof;
	while (roof--) {
		int mSize, fSize;
		//input member, fan
		cin >> member >> fan;

		cout << solve(member, fan) << endl;
	}
	return 0;
}