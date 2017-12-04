/*
Leetcode 2: Add Two Numbers

** Description **
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

** Examples **
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

** Definition for singly-linked list ** 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
*/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(0),
                 *cr = ret, *pl = l1, *pr = l2;

        int carried = 0;
        while (pl != nullptr || pr != nullptr) {
            int vl = (pl != nullptr) ? pl->val : 0,
                vr = (pr != nullptr) ? pr->val : 0;
            cr->next = new ListNode(vl + vr + carried);
            cr = cr->next;
            if (cr->val >= 10) {
                cr->val %= 10;
                carried = 1;
            } else {
                carried = 0;
            }
            if (pl != nullptr)
                pl = pl->next;
            if (pr != nullptr)
                pr = pr->next;
        }
        if (carried == 1) {
            cr->next = new ListNode(1);
        }
        cr = ret->next;
        delete ret;
        return cr;
    }
};