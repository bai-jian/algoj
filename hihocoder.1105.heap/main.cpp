#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> heap;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char operation;
		cin >> operation;
		if (operation == 'A')
		{
			int W;
			cin >> W;
			heap.push(W);
		}
		else
		{
			cout << heap.top() << endl;
			heap.pop();
		}
	}
}
