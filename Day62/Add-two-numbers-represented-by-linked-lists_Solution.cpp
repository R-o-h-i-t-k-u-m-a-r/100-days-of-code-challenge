//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //First reverse both linked list for adding digit efficiently
        first=reverse(first);
        second=reverse(second);
        
        int carry=0;
        Node *sum=NULL;
        //Traverse each node of both linked list and if there will remain carry then
        //one more traversal for that digit
        while(first!=NULL || second!=NULL ||carry!=0){
            
            //store carry and both linked list data in one variable
            int data=carry;
            if(first){
                data+=first->data;
            }
            if(second){
                data+=second->data;
            }
            
            //finding carry for adding next digits
            carry=data/10;
            
            //taking right most digit
            data=data%10;
            
            //Making new Node with sum data
            Node *temp=new Node(data);
            temp->next=sum;
            sum=temp;
            
            //moving ahead in both lists.
            if(first) first = first->next; 
            if(second) second = second->next;
        }
        
        //returning newly created linked list
        return sum;
    }
    
    struct Node* reverse(struct Node*  head){
        if(head==NULL){
            
        }
        
        Node *curr= head;
        Node *pre=NULL;
        Node *next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        
        return pre;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends