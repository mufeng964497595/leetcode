/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 任一链表为nullptr，直接返回另一个链表，不需要处理
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        // 为了不养成破坏原始数据的习惯，使用第三个链表来记录结果
        ListNode* ans = nullptr;
        ListNode* pNow = nullptr;
        int add(0);     // 上一步加法的增量
        while (p1 && p2) {
            int val = p1->val + p2->val + add;
            DealVal(val, add);

            if (!ans) {
                ans = new ListNode(val);
                pNow = ans;
            } else {
                ListNode* tmp = new ListNode(val);
                pNow->next = tmp;
                pNow = tmp;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        // 走到这一步，已保证pNow、ans不是空指针
        if (p1) {
            AddList(p1, pNow, add);
        } else {
            AddList(p2, pNow, add);
        }

        // 最后可能还有加法的进位
        if (0 != add) {
            ListNode* tmp = new ListNode(add);
            pNow->next = tmp;
        }

        return ans;
    }

private:
    void DealVal(int& val, int& add) {
        if (val >= 10) {
            // 向前进位
            val -= 10;
            add = 1;
        } else {
            add = 0;
        }
    }

    void AddList(ListNode*& pList, ListNode*& pRes, int& add) {
        while (pList) {
            int val = pList->val + add;
            DealVal(val, add);
            ListNode* tmp = new ListNode(val);
            pRes->next = tmp;
            pRes = tmp;

            pList = pList->next;
        }
    }
};
// @lc code=end
