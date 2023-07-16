//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
        
    bool f=true;
    
    for(int i=0; i<num; i++){
        if((i==K-1) || (i==num - K)){
            if(!((before[K-1] == after[num - K]) && (before[num-K] == after[K-1]))) f=0;
        }
        else{
            if(before[i] != after[i]) f=0;
        }
    }
    
    return f;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    //if k is more than number of nodes or kth node from beginning 
    //and end are same, we retuen the list.
    if (K > num) 
      return head;
    if(2*K-1 == num) return head;
    
    Node* x_prev = NULL;
    Node* x = head;
    
    Node* y_prev = NULL;
    Node* y = head;
    
    int count = K-1;
    
    //finding the kth node from the beginning of list. We also find node
    //previous of kth node because we need to update next pointer of 
    // the previous node. 
    while(count--){
        x_prev = x;
        x = x->next;
    }
    
    count = num - K;
    
    //similarly, finding the kth node from end and its previous node. kth node 
    //from end is (num-k+1)th node from beginning .
    while(count--){
        y_prev = y;
        y = y->next;
    }
    
    //if x_prev exists, then new next of it will be y.
    if(x_prev)
        x_prev->next = y;
    //if y_prev exists, then new next of it will be x.
    if(y_prev)
        y_prev->next = x;
    
    //we will swap the next pointers of x and y.    
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    //changing head pointers when k is 1 or num. 
    if(K == 1)
        return y;
    if(K == num)
        return x;
    return head;    
    
    
}
