#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    if(head->next == NULL){
        head->next = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

node *reverse(node *head){
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* rotateList(node* &head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head;
    int len = 0;
    while(slow != NULL){
        len++;
        slow = slow->next;
    }
    k = k%len;
    slow = head;
    while(k--){
        fast = fast->next;
    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);

    node* ans = rotateList(head,2);
    display(head);

    return 0;
}