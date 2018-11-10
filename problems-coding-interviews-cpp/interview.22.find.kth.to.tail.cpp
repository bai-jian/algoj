struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode * FindKthToTail(ListNode *pListHead, unsigned int k)
	{
		if (pListHead == nullptr)
			return nullptr;

		ListNode *fast = pListHead;
		for (int i = 0; i < k; i++)
		{
			if (fast == nullptr)
				return nullptr;
			fast = fast->next;
		}

		ListNode *slow = pListHead;
		while (fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
	}
};
