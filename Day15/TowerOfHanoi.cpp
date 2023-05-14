//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int s, int d, int h) {
        //if there will be only one disk then move from source to destination and return
        if(N==1)
        {
            cout<<"move disk 1 from rod "<<s<<" to rod "<<d<<endl;
            return 1;
        }
        //moving N-1 disks from source rod to helper rod with the help of 
        //distination rod
        long long  first=toh(N-1,s,h,d)+1;
        
        cout<<"move disk "<<N<<" from rod "<<s<<" to rod "<<d<<endl;
        //After moving N-1 disks to helper rod 
        //again moving these disks from helper rod to distation rod with the help of 
        //source rod
        long long second=toh(N-1,h,d,s);
        
        //Now finally returing total number of moves.
        return first+second;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends