#include <cstring>

class Solution
{
public:
	void replaceSpace(char *str, int length)
	{
		int counter = 0;
		for (int i = 0; i < length; i++)
			if (str[i] == ' ')
				++counter;

		int i = length;
		int j = length + 2 * counter;
		while (i >= 0)
		{
			if (str[i] != ' ')
				str[j--] = str[i--];
			else
			{
				strncpy(&str[j - 2], "%20", 3);
				--i;
				j -= 3;
			}
		}
	}
};