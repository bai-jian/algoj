#include "LinkedList.h"

ListNode *LinkedList::reverse(ListNode* head)
{
	ListNode *newHead = nullptr;
	while (head)
	{
		ListNode *node = head;
		head = head->next;
		node->next = newHead;
		newHead = node;
	}
	return newHead;
}

ListNode *LinkedList::findKthToTail(ListNode *head, unsigned int k)
{
	ListNode *fast = head;
	for (int i = 0; i < k; i++)
	{
		if (fast == nullptr)
			return nullptr;
		fast = fast->next;
	}

	ListNode *slow = head;
	while (fast != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

vector<int> &LinkedList::printListFromTailToHead(ListNode *head)
{
	if (head == nullptr)
		return vector<int>();
	else
	{
		vector<int> &list = printListFromTailToHead(head->next);
		list.push_back(head->val);
		return list;
	}
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
	ListNode dummy(0), *tail = &dummy;
	while (head1 && head2)
	{
		if (head1->val < head2->val)
		{
			tail = tail->next = head1;
			head1 = head1->next;
		}
		else
		{
			tail = tail->next = head2;
			head2 = head2->next;
		}
	}
	tail->next = head1 ? head1 : head2;
	return dummy.next;
}
