#include <iostream>
#include <string>
using namespace std;

//static const int MAX_SIZE = 1048576;
//
//char decompressed[MAX_SIZE][MAX_SIZE];
//void decompress(string::iterator &it, int y, int x, int size)
//{
//	// 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
//	char head = *(it++);
//	// 한 글자를 검사할 때마다 b 또는 w인 경우
//	if (head == 'b' || head == 'w')
//	{
//		for (int dy = 0; dy < size; ++dy)
//			for (int dx = 0; dx < size; ++dx)
//				decompressed[y + dy][x + dx] = head;
//	}
//	else
//	{
//		// 네 부분을 각각 순서대로 압축 해제한다.
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
	// 각각 위와 아래 조각들의 위치를 바꾼다.
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
//	// 4개의 부분을 각각 재귀호출
//	// 4부분 모두 w또는 b라면 반환
//	// 4부분을 합쳐서 최종 반환
//}
//
//int main(void)
//{
//	int C;
//	cin >> C;
//
//	// 위아래를 뒤집는다.
//	// 기존에 있는 모양을 뒤집어서 바꾼다.
//	while (C--)
//	{
//		string tree;
//		cin >> tree;
//	}
//
//	return 0;
//}