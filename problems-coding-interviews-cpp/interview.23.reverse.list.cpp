struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		ListNode *pNewHead = nullptr;
		while (pHead)
		{
			ListNode *ptr = pHead->next;
			pHead->next = pNewHead;
			pNewHead = pHead;
			pHead = ptr;
		}
		return pNewHead;
	}
};
