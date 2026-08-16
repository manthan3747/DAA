class Solution {
public:

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            }
            else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        if (a != NULL)
            temp->next = a;
        else
            temp->next = b;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* first = sortList(head);
        second = sortList(second);

        return merge(first, second);
    }
};