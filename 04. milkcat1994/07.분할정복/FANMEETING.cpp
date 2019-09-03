/*
--����Ʈ���� ���׸����̼� ������ �߻��ϳ� ������ ���� ���ε� ����
���� : https://algospot.com/judge/problem/read/FANMEETING
���� ����� ���� ���̵� �׷����� ��׽� �Ͽ� �ö� �ִ� ȥ�� �� �׷� �����۽ôϾ
���� 10�ֳ� ��� �� ������ �����߽��ϴ�.
�� ������ �� ������, ������ ������ �ҵ��� ������ �ϴ� ��縦 ����� �߽��ϴ�.
�����۽ôϾ��� ������� �켱 ���뿡 �Ϸķ� ���ϴ�.
�� ���ÿ� ������ M���� �ҵ��� ���� ���� �� ������ ����������� ������ �� �� �������� �����̸�
������ �ϳ��� ������ �մϴ�. ��� �ҵ��� ���ÿ� �� �� �����Դϴ�.
�Ʒ� �׸��� ��� ������ �Ϻθ� �����ݴϴ�.
a~d�� �� ���� �����۽ôϾ� ������̰�,
0~5�� ���� ���� �ҵ��Դϴ�.

������ �����۽ôϾ��� ���� ������� ���� �Ұ� �����ϱⰡ �θ��ϴٰ� ���ܼ�,
���� �Ұ��� ���� ��� �Ǽ��� �ϱ�� �߽��ϴ�.
���� �� ������ �ҵ��� ������ ���� �־��� �� �� ������ ����Ǵ� ��������
�����۽ôϾ��� ��� ����� ���ÿ� ������ �ϴ� ���� �� ���̳� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��20)�� �־����ϴ�.
�� �׽�Ʈ ���̽��� ������� ������ �ҵ��� ������ ���� ��Ÿ���� �� ���� ���ڿ��� �����Ǿ� �ֽ��ϴ�.
�� ���ڿ��� ���ʺ��� ������ ������� �� ������� ������ ��Ÿ���ϴ�.

M�� �ش��ϴ� ����� ����, F�� �ش��ϴ� ����� �������� ��Ÿ���ϴ�.
����� ���� ���� ���� ��� 1 �̻� 200,000 ������ �����̸�, ����� ���� �׻� ���� �� �����Դϴ�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� ��� ������� ������ �ϴ� ���� �� ���̳� �ִ��� ����մϴ�.
*/

/*
���� �Է�
4
FFFMMM
MMMFFF
FFFFF
FFFFFFFFFF
FFFFM
FFFFFMMMMF
MFMFMFFFMMMFMF
MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF

���� ���
1
6
2
2
*/

//Ǯ�̹�� �����
/*
��� ����� ���ÿ� ���𰡸� �Ѵٸ� Ƚ���� ���, ���� ���� N, M���� �� ���
|N-M|+1

���� ��� ����� ���ÿ� ������ �Ұ���� ����
M M F F  =>  M F F  =>  M F
M F M F  =>  F M F  =>  F X

AND����� ���� ����� ����
M = 1, F = 0���� ġȯ�Ͽ� ��Ʈ�� ����Ʈ ������ �̿��Ͽ� ������� 0�� �ƴҰ��
Ʋ�� ����̴�.

������ : ��Ʈ ���̰� �ִ� 20������ ����� ������ �Ұ��ϴ�.
==> �ڸ����� �� ������ ������ �� �� �ִ� �˰����� �����Ѵ�. [ī���߹� �˰���]
:: https://sangdo913.tistory.com/22
*/

//ī���߹� �˰���
/*
x,y�� �����Ѵ�.
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
��, z1 = (x1 + x0)(y1 + y0) - z2 - z0


��::
B = 10 �̶��ϰ�, m = 2 �� ����. 1234�� 5678�� ���� ���ϰ� ������,

12 34 = 12 �� 10^2 + 34
56 78 = 56 �� 10^2 + 78
z2 = 12 �� 56 = 672
z0 = 34 �� 78 = 2652
z1 = (12 + 34)(56 + 78) ? z2 ? z0 = 46 �� 134 ? 672 ? 2652 = 2840
��� = z2 �� 10^(2��2) + z1 �� 10^2 + z0 = 672 �� 10000 + 2840 �� 100 + 2652 = 7006652

=>z0, z1, z2�� ī������ �˰��� �̿��Ͽ� ���ϱ�.
*/
/*
���� ����� ����ŭ �߶�, �񱳸� �ǽ��Ѵ�.
���� ��� ���� ī���߹� �˰��� ����.
1. ���Ҷ� if�� ��� �Ͽ� ��
2. 
���� : ���� �ϳ��� 0 or F��� ��ġ�� ����̴�.
*/

/*
N -> ����� ��
M -> �ҵ��� ��
(M-N+1)*N^log3...?  ����.....
���� (M-N+1) => ��� ���ؾߵǾ� �� �ʿ��ѵ�...
���� N => ī������ �˰����� N

�� ���ڸ� ������ ���η� �������� ���� Ȯ�� ��
�ѹ��� ���� ������ �ʾƵ� ���� �� �� �ִ�. <- å�� ��������.

�׸��Ͽ� N^log3�� ������ ����.
������ ��� ���� ���� �ٲپ��
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

//���� ���� ����ȭ �۾�
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
	//a,b���� /2 !=0 �̶�� ������
	vector<int> tempResult;
	//�ϳ��� vector�� ����ִ°��
	if (m.size() > f.size()) return karatsuba(f, m);
	if (m.empty() || f.empty()) return vector<int>();
	//����� 50 ���϶�� �Ϲ����� �������� ����Ѵ�.
	if (f.size() <= 50) {
		return multiply(m, f);
	}

	//�������� ������ ��� m�� ��� f�� ���ݺ��� size�� ���� ���� ������ ���
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

	//half�� m,f���� ��°��� �ƴ� �ϳ��� ���� �ؾ��Ѵ�.
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
	//M�� �Ųٷ� ����
	for (int i = 0; i<mSize; ++i) {
		member[mSize-i-1] == 'M' ? M[i] = 1 : M[i] = 0;
	}

	for (int i = 0; i<fSize; ++i) {
		fan[i] == 'M' ? F[i] = 1 : F[i] = 0;
	}
	resultV = karatsuba(M, F);

	//Ȯ���� ������ �������־�� �Ѵ�.
	//Ȯ�� ������ Ƚ��
	int length = fSize - mSize + 1;
	//Ȯ�� ������ Point
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