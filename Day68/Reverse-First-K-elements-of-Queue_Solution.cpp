//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // Taking Stack to store first k elements of queue
    stack<int> s;
    int temp=k;
    while(temp!=0){
        s.push(q.front());
        q.pop();
        temp--;
    }
    
    //Now inserting stack elements back to queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    //Since we have inserted first k elements at the rear of queue so we need to flip
    //those elments which lies after kth position in queue
    int flip=q.size()-k;
    while(flip!=0){
        q.push(q.front());
        q.pop();
        flip--;
    }
    
    return q;
}