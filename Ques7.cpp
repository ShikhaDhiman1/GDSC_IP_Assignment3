#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(!list1) return list2;
        else if(!list2) return list1;

        ListNode* head = NULL;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }

        ListNode* temp = head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(!list1) temp->next = list2;
        else temp->next = list1;

        return head;
    }
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        if(!list1) return list2;
        else if(!list2) return list1;

        ListNode* head = NULL;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }

        ListNode* temp = head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(!list1) temp->next = list2;
        else temp->next = list1;

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* ans = lists[0];

        for(int i = 1; i < lists.size(); i++){
            ans = merge(ans, lists[i]);
        }
        return ans;
    }
};