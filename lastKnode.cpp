#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val){
    node *n = new node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node *&head, int val){
    node *n = new node(val);
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int lenght(node *&head){
    node *temp = head;
    int l = 0;
    while(temp != NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node *appendK(node *&head, int k){
    node *newHead;
    node *newTail;
    node *tail = head;
    int count = 1;
    int l = lenght(head);
    k  = k%l;
    while(tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;

    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    int n;cin>>n;
    node *head = NULL;
    for(int i = 1; i <= n; i++){
        insertAtTail(head,i);
    }
    display(head);

    node *newhead = appendK(head,3);
    display(newhead);

    return 0;
}