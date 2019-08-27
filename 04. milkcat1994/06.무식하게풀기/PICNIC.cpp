/*
code : https://algospot.com/judge/problem/read/PICNIC
�ȵ�θ޴� ��ġ�� �ͽ��������ݿ����� ���� �ֿ� ������������ ��ǳ�� ���ϴ�.
���� �������� ��ǳ �� �л����� �� �� ¦�� ���� �ൿ�ϰ� �Ϸ��� �մϴ�.
�׷��� ���� ģ���� �ƴ� �л��鳢�� ¦�� ���� �ָ� ���� �ο�ų� ���� ���ƴٴ��� �ʱ� ������,
�׻� ���� ģ���� �л��鳢���� ¦�� ����� �մϴ�.
�� �л����� �ֿ� ���� �̵��� ���� ģ������ ���ΰ� �־��� ��, �л����� ¦ ���� �� �ִ�
����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. ¦�� �Ǵ� �л����� �Ϻθ�
�ٸ����� �ٸ� ����̶�� ���ϴ�. ���� ��� ���� �� ���� ����� ���� �ٸ� ����Դϴ�.
(�¿�, ����ī) (���, Ƽ�Ĵ�) (ȿ��, ����)
(�¿�, ����ī) (���, ����) (ȿ��, Ƽ�Ĵ�)

1�� ���� ���� �Ǿ�� �ϰ� 64MB ���� �޸� ���
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (C <= 50) �� �־����ϴ�.

�� �׽�Ʈ ���̽��� ù �ٿ��� �л��� �� n (2 <= n <= 10) ��
ģ�� ���� �� m (0 <= m <= n*(n-1)/2) �� �־����ϴ�.
�� ���� �ٿ� m ���� ���� ������ ���� ģ���� �� �л��� ��ȣ�� �־����ϴ�.
��ȣ�� ��� 0 ���� n-1 ������ �����̰�, ���� ���� �Է¿� �� �� �־����� �ʽ��ϴ�.
�л����� ���� ¦���Դϴ�.
*/

/*
�Է�
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

(0, 1) (1, 2) (2, 3) (3, 0) (0, 2) (1, 3)
���
1
3
4
*/

//0���� 10���� ������� ���鼭 ������ ¦�� ���� �� �ִ��� Ȯ��,
//���� �� �ִٸ� �׻���� ���� �ȵǰ� ��� �ص� ��.
//���� ��� �ߺ��Ǵ� ��찡 ���� 0,1 2,3 / 2,3 0,1 ������ �ߺ� ���õ�
//�� ��츦 ���ֱ� ���� ���õ��� ���� �� �� ���� ���� ������ ���� ���ָ� ��.
#include <iostream>
using namespace std;

//�л��� ���� ���� �迭
bool connectArr[10][10] = {};
//�л� ��
int snum=0;

int countConnect(bool selected[]) {
	int res = 0;
	int startPoint = -1;

	//���� ������ �ʴٸ� �ش� �л��� ���� Ȯ���Ѵ�.
	for (int i = 0; i < snum; i++)
		if (!selected[i]) {
			startPoint = i;
			break;
		}

	//�� �̻� �� �ʿ䰡 ���ٸ� 1�� ��ȯ �� �� �������� 1�� �����ش�.
	if (startPoint < 0)
		return 1;

	//���õ��� ���� �� �� ���� ���� ���� ��(startPoint)�� Ȯ�� �Ͽ� ������ ������ִ��� Ȯ��.
	for (int i = startPoint+1; i < snum; i++)
		//���õ��� ���� ¦�̶�� ¦ ã��
		if (!selected[startPoint] && !selected[i] && connectArr[startPoint][i]) {
			selected[startPoint] = true; selected[i] = true;
			res += countConnect(selected);
			selected[startPoint] = false; selected[i] = false;
		}

	return res;
}


int main() {
	//���� �ݺ� Ƚ��, ¦�� ��
	int roof, cnum;
	//¦�� ù°, ��°
	int tempf, tempe;
	//�л� ���� Ȯ�� �迭
	cin >> roof;

	while (roof--) {
		//�л��� ���õǾ����� Ȯ���ϴ� �迭
		bool isSelectedStudent[10] = {};
		cin >> snum >> cnum;
		//¦�� �ʱ�ȭ
		while (cnum--) {
			cin >> tempf >> tempe;
			if(tempf<tempe)
				connectArr[tempf][tempe] = true;
			else
				connectArr[tempe][tempf] = true;
		}
		//���� ���� ���
		cout << countConnect(isSelectedStudent) << endl;

		//���� ���� �ʱ�ȭ
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				connectArr[i][j] = false;
	}
	return 0;
}