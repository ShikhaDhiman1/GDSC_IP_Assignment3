#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* reverseDLL(struct Node * head)
{
    struct Node* temp = NULL;
    struct Node* curr = head;
    
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    
    if(temp != NULL){
        head = temp->prev;
    }
    
    return head;
}
