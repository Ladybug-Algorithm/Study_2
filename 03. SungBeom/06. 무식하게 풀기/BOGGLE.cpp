#include <iostream>
#include <string>
using namespace std;

const int X_MAX = 5;
const int Y_MAX = 5;

char words[X_MAX][Y_MAX] =
{ {'U', 'R', 'L', 'P', 'M'},
{'X', 'P', 'R', 'E', 'T'},
{'G', 'I', 'A', 'E', 'T'},
{'X', 'T', 'N', 'Z', 'Y'},
{'X', 'O', 'Q', 'R', 'S'} };
char answer[X_MAX][Y_MAX];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool inRange(int x, int y)
{
	return x >= 0 && x < X_MAX && y >= 0 && y < Y_MAX;
}

bool hasWord(int x, int y, const string& word)
{
	if (!inRange(x, y)) return false;
	if (words[x][y] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int i = 0; i < 8; i++)
		if (hasWord(x + dx[i], y + dy[i], word.substr(1))) return true;
	return false;
}

int main(void)
{
	const string const word[7] = { "PRETTY", "GIRL", "REPEAT", "FAIL", "MEAT", "SUCCESS", "GIANT" };

	bool success;
	for (int i = 0; i < sizeof(word)/sizeof(string); i++)
	{
		success = false;
		for (int j = 0; j < X_MAX; j++)
		{
			for (int k = 0; k < Y_MAX; k++)
				if (hasWord(j, k, word[i]))
				{
					success = true;
					break;
				}
			if (success) break;
		}

		cout << word[i];
		if (success) cout << " success!\n";
		else cout << " fail...\n";
	}

	return 0;
}