#include <iostream>
#include <string>
#include <stack>
using namespace std;

const char left1 = '(', left2 = '{', left3 = '[';
const char right1 = ')', right2 = '}', right3 = ']';

int main(void)
{
	int C;
	cin >> C;

	while (C--)
	{
		string brackets;
		cin >> brackets;

		stack<char> bracket;
		bool success = true;
		for (int i = 0; i < brackets.size(); i++)
		{
			if (brackets[i] == left1 || brackets[i] == left2 || brackets[i] == left3)
				bracket.push(brackets[i]);
			else if (brackets[i] == right1)
			{
				if (bracket.empty())
				{
					success = false;
					break;
				}
				else if (bracket.top() != left1)
				{
					success = false;
					break;
				}
				else
					bracket.pop();
			}
			else if (brackets[i] == right2)
			{
				if (bracket.empty())
				{
					success = false;
					break;
				}
				else if (bracket.top() != left2)
				{
					success = false;
					break;
				}
				else
					bracket.pop();
			}
			else if (brackets[i] == right3)
			{
				if (bracket.empty())
				{
					success = false;
					break;
				}
				else if (bracket.top() != left3)
				{
					success = false;
					break;
				}
				else
					bracket.pop();
			}
		}

		if (success && bracket.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}