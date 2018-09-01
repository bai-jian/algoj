#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

main()
{
	int N, M;
	cin >> N >> M;

	// Applying map instead of unordered_map results in TLE.
	unordered_map<string, int> cache;

	string url;
	int timestamp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> url;
		++timestamp;

		auto record = cache.find(url);
		if (record != cache.end())
		{
			cout << "Cache" << endl;
			record->second = timestamp;
		}
		else
		{
			cout << "Internet" << endl;
			if (cache.size() == M)
			{
			    // Applying the algorithm min_element results in TLE.
			    /*
                auto lru = min_element(cache.cbegin(), cache.cend(),
                    [](const pair<string,int> &record1, const pair<string,int> &record2) {
                        return record1.second < record2.second;
                    });
                */
				auto lru = cache.begin();
				for (auto it = cache.begin(); it != cache.end(); ++it)
					if (it->second < lru->second)
						lru = it;
				cache.erase(lru);
			}
			cache.emplace(url, timestamp);
		}
	}
}
