/*
���� : https://algospot.com/judge/problem/read/QUADTREE
�뷮�� ��ǥ �����͸� �޸� �ȿ� ������ �����ϱ� ���� ����ϴ� ���� ��� �� ���� Ʈ��(quad tree)�� ���� �ֽ��ϴ�. �־��� ������ �׻� 4���� ������ ��������� ǥ���ϱ� ������ ���� Ʈ����� �̸��� �پ��µ�, ���� ������ ���ó �� �ϳ��� ���� ���� �� ���ۿ� ���� ��� �׸��� ������ ǥ���ϴ� ���Դϴ�. ���� Ʈ���� 2N �� 2N ũ���� ��� �׸��� ������ ���� ������ ���� ���ڿ��� �����մϴ�.

�� �׸��� ��� �ȼ��� ���� ���� ��� �� �׸��� ���� Ʈ�� ���� ����� �׸��� ũ�⿡ ������� b�� �˴ϴ�.
�� �׸��� ��� �ȼ��� �� ���� ��� �� �׸��� ���� Ʈ�� ���� ����� �׸��� ũ�⿡ ������� w�� �˴ϴ�.
��� �ȼ��� ���� ���� �ƴ϶��, ���� Ʈ���� �� �׸��� ���� ���η� ���� 2����� 4���� �������� �ɰ� �� ������ ���� Ʈ�� �����մϴ�. �̶� ��ü �׸��� ���� ����� x(���� �� �κ��� ���� ���)(������ �� �κ��� ���� ���)(���� �Ʒ� �κ��� ���� ���)(������ �Ʒ� �κ��� ���� ���)�� �˴ϴ�. ���� ��� �׸� (a)�� ���� �� 4�и��� xwwwb�� ����˴ϴ�.
�׸� (a)�� �׸� (b)�� 16��16 ũ���� ���� �׸��� ���� Ʈ���� ��� ������ �����ϴ����� �����ݴϴ�. �̶� ��ü �׸��� ���� ����� xxwww bxwxw bbbww xxxww bbbww wwbb�� �˴ϴ�.

���� Ʈ���� ����� ��� �׸��� �־����� ��, �� �׸��� ���Ϸ� ������ �׸� �� ���� Ʈ�� �����ؼ� ����ϴ� ���α׷��� �ۼ��ϼ���.

ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�. �� �� C�ٿ� �ϳ��� ���� Ʈ���� ������ �׸��� �־����ϴ�. ��� ���ڿ��� ���̴� 1,000 �����̸�, ���� �׸��� ũ��� 220 �� 220 �� ���� �ʽ��ϴ�.

���
�� �׽�Ʈ ���̽��� �� �ٿ� �־��� �׸��� ���Ϸ� ������ ����� ���� Ʈ�� �����ؼ� ����մϴ�.

*/

/*
���� �Է�
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

���� ���
w
xwbbw
xxbwwbbbw
xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
*/
//x( x(wwwb) x(wx(wbbb)ww) x(x(x(wwbb)bww)wwb) b)
#include <iostream>
#include <vector>

using namespace std;
vector<char> quadtree;
vector<char> result;

//��, �� �� ����, �ڸ� ���� Ȯ���ϱ�.
//�� ��� �� x�� ���� ���
int rotateQuadTree(int start, int end) {
	//�� �̻� �� �ʿ� ���� ��
	if (end == start) {
		result.push_back(quadtree[start]);
		return 0;
	}
	else if (end-start == 1) {
		result.push_back(quadtree[start]);
		result.push_back(quadtree[end]);
		return 0;
	}

	//x�� ���ö� ���� �ݺ��ؼ� ã��, ������ �ʴ´ٸ� result�� �߰�.
	//x���� �տ� ������ w,b �� ��� ������ �̹� ���
	for (int i = start; i < quadtree.size(); i++) {
		if (quadtree[i] == 'x')
			break;
		result.push_back(quadtree[i]);
		start += 1;
	}

	//�⺻ �� ��ġ�� x���� 2������
	int sPointE = start + 2;

	//�� ���� ���� ã��
	//�翬�� �Ǿ��� x�̹Ƿ� �� �ʿ� x
	for (int i = start+1; sPointE >= i; i++) {
		if (quadtree[i] == 'x') {
			sPointE += 4;
		}
	}

	int ePointE = sPointE + 2;
	//�� ���� ����
	for (int i = sPointE + 1; ePointE >= i; i++) {
		if (quadtree[i] == 'x') {
			ePointE += 4;
		}
	}

	//��
	result.push_back('x');
	rotateQuadTree(sPointE+1, ePointE);

	//��
	rotateQuadTree(start+1, sPointE);
	//x���� �ڿ� ������ �κ��� �����״� ����Ȯ��

	if (ePointE != end) {
		rotateQuadTree(ePointE + 1, end);
	}
	return 0;
}

int main() {
	int roof;
	char tempC;

	cin >> roof;
	while (roof--) {
		int length = 1;
		for (int i = 0; length > i; i++) {
			cin >> tempC;
			quadtree.push_back(tempC);
			if (tempC == 'x') {
				length += 4;
			}
		}
		rotateQuadTree(0, quadtree.size()-1);
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
		cout << endl;
		quadtree.clear();
		result.clear();
	}
	return 0;
}