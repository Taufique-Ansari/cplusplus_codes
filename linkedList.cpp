#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int val){
        data = val; 
        next = NULL;
    }
};

void insertAtHead(node *&head, int val){
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val){
    node *n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp ->next;
    }cout<<"NULL"<<endl;
}

bool search(node *head, int key){
    node *temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deleteAtHead(node *&head){
    node *toDel = head;
    head = head->next;

    delete toDel;
}

void deletion(node *&head, int val){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

node *reverse(node *&head){
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

node *reverseRecussively(node *&head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *newhead = reverseRecussively(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

int main()
{
    node *head = NULL;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        insertAtTail(head,i);
    }
    display(head);
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
        //DELETION
    // cout<<search(head,3)<<endl;
    // for(int i = 1; i <= n; i++){
    //     if(i%2 != 0){
    //         if(i == 1){
    //             deleteAtHead(head);
    //         }else{
    //             deletion(head,i);
    //         }
    //     }else{
    //         continue;
    //     }
    // }
    // deletion(head,4);
    // deleteAtHead(head);
        //REVERSE
    // node *newhead = reverse(head);
    node *newhead = reverseRecussively(head);
    display(newhead);

    return 0;
}