/*
���� : https://algospot.com/judge/problem/read/FENCE
�ʺ� ���� N���� ���� ���ڸ� �ٿ� ���� ��Ÿ���� �ֽ��ϴ�.
�ð��� ������ ���� ���ڵ��� �η����ų� ������ ���̰� �� �޶��� �����
��Ÿ���� ��°�� ��ü�ϱ�� �߽��ϴ�.
�� �� ������ ��Ÿ���� �Ϻθ� ���簢������ �߶� ��Ȱ���ϰ� �ͽ��ϴ�.
�׸� (b)�� (a)�� ��Ÿ������ �߶� �� �ִ� ���� ���簢�� �� ���� ���� ���簢���� �����ݴϴ�.
��Ÿ���� �����ϴ� �� ������ ���̰� �־��� ��,
�߶� �� �ִ� ���簢���� �ִ� ũ�⸦ ����ϴ� ���α׷��� �ۼ��ϼ���.
�� (c)ó�� ���簢���� �񽺵��� �߶� ���� �����ϴ�.

������ �ʺ�� ��� 1�̶�� �����մϴ�.

�Է�
ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�.
�� �׽�Ʈ ���̽��� ù �ٿ��� ������ �� N (1��N��20000)�� �־����ϴ�.
�� ���� �ٿ��� N���� ������ ���ʺ��� �� ������ ���̰� ������� �־����ϴ�.
���̴� ��� 10,000 ������ ���� �ƴ� �����Դϴ�.

���
�� �׽�Ʈ ���̽��� ���� �ϳ��� �� �ٿ� ����մϴ�.
�� ������ �־��� ��Ÿ������ �߶� �� �ִ� �ִ� ���簢���� ũ�⸦ ��Ÿ���� �մϴ�.
*/

/*
���� �Է�
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4
1 8 2 2

���� ���
20
16
8
*/

//�̹� ���� �ö� Point ��� ���� Point�� �����Ͽ� �ش� ���̿��� ���� �� �ִ�
//�ִ� ���̸� ��ȯ �ϴ� �Լ� ȣ��.
//�Լ� ������ ���� Result�� �����ϱ� 
//�� ���� �ݺ� �� �� �ִ� �� ���.

/*
ó�� 2���� Ȯ�� Ȯ��
�ִ���̱��� ��� �����ϴ� �׷����� ���°� �ι� �ݺ��� �ȴٸ�
�־��� ����� �� 1������ Point�� ����� and �ش� 1������ Point��
fecnce�� size��ŭ 2���� �ݺ�
������ �� : N
N+ (N/2) * N -> N + N^2 ?
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> fence;
set<int> targetNum;

//�ִ� ���� ��ȯ�� ��
int findMaxArea(int num) {
	int tempResult = 0, maxArea = 0;

	//��� �� Ȯ��
	for (int i = 0; i < fence.size(); i++) {
		//Point���� ���̺��� �۴ٸ� ���̿� ���ϱ�
		if (num <= fence[i]) {
			tempResult += num;
		}
		//���̺��� ���ٸ� ���̷� �������� ����.
		//���ݺ��� ū ���̸� ���ߴٸ� ����
		else {
			if (maxArea < tempResult)
				maxArea = tempResult;
			tempResult = 0;
		}
	}
	return maxArea;
}

int findPoint() {
	int exNum = fence[0];

	for (int i = 1; i < fence.size(); i++) {
		//�̹� ���ڰ� �ö�� Point��� ����
		if (exNum <= fence[i]) {
			exNum = fence[i - 1];
			//set�� �̿��Ͽ� Ȯ���� ���ڸ� �����Ѵ�.
			targetNum.insert(exNum);
		}
	}

	//���� �ص� ���̸� �̿��Ͽ� �ִ� ���� ���ϱ�
	int result=0;
	set<int>::iterator iter;
	for (iter = targetNum.begin(); iter != targetNum.end(); ++iter) {
		int tempResult = findMaxArea(*iter);
		if (result < tempResult)
			result = tempResult;
	}

	return result;
}

int main() {
	int roof, tempNum, result;

	cin >> roof;
	while (roof--) {
		int legnth;
		cin >> legnth;
		for (int i = 0; legnth > i; i++) {
			cin >> tempNum;
			fence.push_back(tempNum);
		}
		result = findPoint();
		cout << result << endl;
		fence.clear();
	}
	return 0;
}