#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head == nullptr)
			return vector<int>();
		else
		{
			vector<int> list = printListFromTailToHead(head->next);
			list.push_back(head->val);
			return list;
		}
	}
};