// #Find The Min Max Number Of Nodes between two critical points

#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
        int data; 
        node *next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

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
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

vector<int> nodeBetweenCriticalPoint(node* &head){
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    node* prev = head;
    if(!prev) return ans;
    node* curr = prev->next;
    if(!curr) return ans;
    node* next = curr->next;
    if(!next) return ans;

    int first = -1;
    int last = -1;
    int i = 1;
    int minD = INT_MAX;

    while(curr){
        bool isCP = ((curr->data > prev->data && curr->data > next->data) || (curr->data < prev->data && curr->data < next->data))?true : false;
        if(isCP && first == -1){
            first = i;
            last = i;
        }
        else if(isCP){
            minD = min(minD,i-last);
            last = i;
        }
        i++;
        prev = curr;
        curr = next;
        next = next->next;
    }
    if(first == last){
        return ans;
    }else{
        ans[0] = minD;
        ans[1] = last - first;
    }

    return ans;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,5);   
    insertAtTail(head,3);   
    insertAtTail(head,1);   
    insertAtTail(head,2);   
    insertAtTail(head,5);   
    insertAtTail(head,1);   
    insertAtTail(head,2);   
    display(head);

    vector<int> ans = nodeBetweenCriticalPoint(head);

    return 0;
}