#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ListNode* slow = head;
        // ListNode* fast = head;

        // while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        //     slow = slow->next;
        //     fast = fast->next->next;

        //     if(slow == fast){
        //         return slow;
        //     }
        // }
        // return NULL;

        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;

        while(temp){
            if(!visited[temp]){
                visited[temp] = true;
            }
            else if(visited[temp]){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};