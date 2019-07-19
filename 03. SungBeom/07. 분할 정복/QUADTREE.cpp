#include <iostream>
#include <string>
using namespace std;

//static const int MAX_SIZE = 1048576;
//
//char decompressed[MAX_SIZE][MAX_SIZE];
//void decompress(string::iterator &it, int y, int x, int size)
//{
//	// �� ���ڸ� �˻��� ������ �ݺ��ڸ� �� ĭ ������ �ű��.
//	char head = *(it++);
//	// �� ���ڸ� �˻��� ������ b �Ǵ� w�� ���
//	if (head == 'b' || head == 'w')
//	{
//		for (int dy = 0; dy < size; ++dy)
//			for (int dx = 0; dx < size; ++dx)
//				decompressed[y + dy][x + dx] = head;
//	}
//	else
//	{
//		// �� �κ��� ���� ������� ���� �����Ѵ�.
//		int half = size / 2;
//		decompress(it, y, x, half);
//		decompress(it, y, x + half; half);
//		decompress(it, y + half, x, half);
//		decompress(it, y + half, x + half, half);
//	}
//}

string reverse(string::iterator &it)
{
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	// ���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�.
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		string tree;
		cin >> tree;
		string::iterator it = tree.begin();

		cout << reverse(it) << '\n';
	}

	system("pause");
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string reverse(string target)
//{
//	if (target[0] == 'x')
//		reverse(target);
//
//	// 4���� �κ��� ���� ���ȣ��
//	// 4�κ� ��� w�Ǵ� b��� ��ȯ
//	// 4�κ��� ���ļ� ���� ��ȯ
//}
//
//int main(void)
//{
//	int C;
//	cin >> C;
//
//	// ���Ʒ��� �����´�.
//	// ������ �ִ� ����� ����� �ٲ۴�.
//	while (C--)
//	{
//		string tree;
//		cin >> tree;
//	}
//
//	return 0;
//}