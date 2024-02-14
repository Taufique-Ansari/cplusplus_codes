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

node* solve(node* &head){
    node* zeroHead = new node(-1);
    node* zeroTail = NULL;

    node* oneHead = new node(-1);
    node* oneTail = NULL;

    node* twoHead = new node(-1);
    node* twoTail = NULL;

    node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(curr->data == 1){
            node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            oneTail->next = temp;
            oneTail = temp;
        }
        else if(curr->data == 2){
            node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            twoTail->next = temp;
            twoTail = temp;
        }
    }

    node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    node* temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    if(oneHead != NULL){
        zeroTail->next = oneHead;
        if(twoHead != NULL){
            oneTail->next = twoHead;
        }
    }else{
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }

    node* temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}

int main()
{
    node* head = NULL;
    insertAtHead(head,1);
    insertAtTail(head,0);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,2);

    node* ans = solve(head);

    return 0;
}