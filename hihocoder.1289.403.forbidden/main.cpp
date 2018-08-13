#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

pair<unsigned, int> addr_stoi(string addr)
{
	unsigned int prefix = 0, mask;

	string::size_type begin = 0;
	string::size_type end = addr.find_first_of(".");
	while (end != string::npos)
	{
		prefix = (prefix << 8) + stoi(addr.substr(begin, end - begin));

		begin = end + 1;
		end = addr.find_first_of(".", begin);
	}

	end = addr.find_first_of("/");
	if (end == string::npos)
	{
		prefix = (prefix << 8) + stoi(addr.substr(begin));
		mask = 32;
	}
	else
	{
		prefix = (prefix << 8) + stoi(addr.substr(begin, end - begin));
		mask = stoi(addr.substr(end + 1));
	}

	int shift = 32 - mask;
	prefix = shift < 32 ? prefix >> shift << shift : 0;

	return {prefix, mask};
}

int main()
{
	int N, M;
	cin >> N >> M;

	/*
	 * In the map, key is a pair of <prefix, mask>, value is a pair of <access, seq>.
	 * access is bool, true for allow, false for deny.
	 * unordered_map may not be applied here because pair offers no hasher functions.
	 */
	map<pair<unsigned, int>, pair<bool, int>> rules;

	for (int i = 0; i < N; i++)
	{
		string str_access, str_addr;
		cin >> str_access >> str_addr;

		auto addr = addr_stoi(str_addr);
		bool access = str_access == "allow" ? true : false;
		rules.emplace(addr, make_pair(access, i));
	}

	for (int i = 0; i < M; i++)
	{
		string str_addr;
		cin >> str_addr;

		auto rule = rules.end();
		auto addr = addr_stoi(str_addr);

		for (int mask = 32; mask >= 0; mask--)
		{
			int shift = 32 - mask;
			unsigned prefix = shift < 32 ? addr.first >> shift << shift : 0;

			auto match = rules.find({prefix, mask});
			if (match != rules.end())
			{
				if (rule == rules.end() || match->second.second < rule->second.second)
					rule = match;
			}
		}

		if (rule == rules.end() || rule->second.first)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
