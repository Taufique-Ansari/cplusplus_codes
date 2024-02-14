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

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void makeCycle(node*& head, int pos){
	node* temp = head;
	node* startnode;
	int count = 1;
	while(temp->next != NULL){
		if(count == pos){
			startnode = temp;
		}
		temp = temp->next;
		count++;
	}
	temp->next = startnode;
}

bool detect(node*& head){
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow){
			return true;
		}
	}
	return false;
}

void removeCycle(node*& head){
	node* slow = head;
	node* fast = head;

	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(fast != slow);

	fast = head;
	while(fast->next != slow->next){
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
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

node* makeCopy(node* head){
    node* temp = head;
    if(temp == NULL){
        return NULL;
    }
    node*  n = new node(temp->data);
    node* newLL = n;
    n->next = makeCopy(temp->next);
    
    return newLL;
}

bool checkPlaindrome(node* head, node* nll){
    while(head != NULL && nll != NULL){
        if(head->data != nll->data){
            return false;
        }
        head = head->next;
        nll = nll->next;
    }
    return true;
}

bool checkPlaindromeNew(node* &head){
    if(head == NULL){
        return true;
    }
    if(head->next == NULL){
        return true;
    }

    node* slow = head;
    node* fast = head->next;
    while(fast != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);

    node* temp1 = head;
    node* temp2 = slow->next;
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main() {
	node* head = NULL;
	insertAtHead(head,0);
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,1);
	insertAtTail(head,0);
	display(head);

    // *****Detect , make and remove a Cyclic Linked list******
        // makeCycle(head,3);
        // cout<<detect(head)<<endl;
        // removeCycle(head);
        // cout<<detect(head);

    // node* nll = makeCopy(head);
    // nll = reverse(nll);
    // display(nll);
    
    // ****1st method to check palindrome*******

        // if(checkPlaindrome(head,nll)){
        //     cout<<"Given Linked List is Palindrome";
        // }else{
        //     cout<<"Not Palindrome";
        // }

    // ****2st method to check palindrome*******

        if(checkPlaindromeNew(head)){
            cout<<"Given Linked List is Palindrome";
        }else{
            cout<<"Not Palindrome";
        }


	return 0;
}
