//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int printKDistantfromLeaf(Node* node, int k);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends


//Node Structure
/*struct Node
{
	int k;
	Node *left, *right;
};*/


//Function to return count of nodes at a given distance from leaf nodes.
void nodeKDistance(Node* root,int k,int arr[],bool visited[],
int Count,int &ans){
    
    //if there is no node then return funtion control
    if(root==NULL){
        return;
    }
    
    //store the node data into array 
    arr[Count]=root->data;
    
    //make node data frequency false at same index since it is visited first time
    visited[Count]=false;
    
    //if we reach to leaf node and we have valid kth index and at frequency array 
    //kth data is not visited twice 
    if(root->left==NULL && root->right==NULL && Count-k>=0 && visited[Count-k]==false)
    {
        //we have found the valid node at kth distance so make the counter increase by one
        ans++;
        
        //since we need to count kth distance node only one times so make the frequency
        //array true at same index so that next time if encounter this node then will not
        //add to counting 
        visited[Count-k]=true;
        
        //after processing this node we need to return the function call to previous state
        return;
    }
    
    //if node is not leaf node then we need to check for left or right node to reach 
    //leaf node by increasing Count by 1 to store next node 
    nodeKDistance(root->left,k,arr,visited,Count+1,ans);
    nodeKDistance(root->right,k,arr,visited,Count+1,ans);
}
int printKDistantfromLeaf(Node* root, int k)
{
    //To solve this problem we will store each node and their corresponding distance
    //from the leaf node so that whenever we reach to leaf node we can find Kth distance
    //node from leaf node
    
    //if we there is no node or not valid kth distacne then returh 0 
    if(root==NULL || k<0){
        return 0;
    }
    
    //Initializing arrary of max height of tree to store all the possible nodes
    int arr[MAX_HEIGHT];
    
    //Innitializing visited array of max height to validate frequency of node
    bool visited[MAX_HEIGHT];
    
    //Assuming initially there is 0 node at kth distance
    int ans=0;
	nodeKDistance(root,k,arr,visited,0,ans);
	
	return ans;
}