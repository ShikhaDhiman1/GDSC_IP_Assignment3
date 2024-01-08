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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* s = head;
        while(s != NULL){
            st.push(s->val);
            s = s->next;
        }

        s = head;
        while(s != NULL){
            if(s->val != st.top()){
                return false;
            }
            st.pop();
            s = s->next;
        }
        return true;
    }
};