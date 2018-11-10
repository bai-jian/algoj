#include <vector>

using std::vector;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList
{
private:
	ListNode *head;

public:
	LinkedList() : head(nullptr) {}

	ListNode *reverse(ListNode *head);

	ListNode *findKthToTail(ListNode *head, unsigned int k);

	vector<int> &printListFromTailToHead(ListNode *head);

	friend ListNode *merge(ListNode *l1, ListNode *l2);
};

ListNode *merge(ListNode *l1, ListNode *l2);
