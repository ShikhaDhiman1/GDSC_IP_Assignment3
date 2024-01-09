#include<bits/stdc++.h> 
using namespace std; 
  
class Node 
{ 
    public: 
        char data; 
        Node* next; 
        Node* pre; 
    Node(int data) 
    { 
        this->data=data; 
        pre=NULL; 
        next=NULL; 
    } 
}; 
  
void rotateByN(Node *&head, int pos) 
{ 
    if (pos == 0) 
        return; 
  
    Node* curr = head; 
  
    while (pos) 
    { 
        curr = curr->next; 
        pos--; 
    } 
  
    Node* tail = curr->pre; 
    Node* NewHead = curr; 
    tail->next = NULL; 
    curr->pre = NULL; 
  
    while (curr->next != NULL) 
    { 
        curr = curr->next; 
    } 
      
    curr->next = head; 
    head->pre = curr; 
    head = NewHead; 
} 