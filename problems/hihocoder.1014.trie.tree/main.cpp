#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string, int> dictionary;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		for (int j = 0; j < word.length(); j++)
		{
			string prefix = word.substr(0, j + 1);
			if (dictionary.find(prefix) == dictionary.cend())
				dictionary.emplace(prefix, 1);
			else
				dictionary[prefix] += 1;
		}

	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string prefix;
		cin >> prefix;
		if (dictionary.find(prefix) == dictionary.cend())
			cout << 0 << endl;
		else
			cout << dictionary[prefix] << endl;
	}
}
