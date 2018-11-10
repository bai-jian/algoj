struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode * Merge(ListNode *pHead1, ListNode *pHead2)
	{
		ListNode newDummyHead(0), *pNewTail = &newDummyHead;
		while (pHead1 && pHead2)
		{
			if (pHead1->val < pHead2->val)
			{
				pNewTail = pNewTail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				pNewTail = pNewTail->next = pHead2;
				pHead2 = pHead2->next;
			}
		}
		pNewTail->next = pHead1 ? pHead1 : pHead2;
		return newDummyHead.next;
	}
};
