//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int Josephus(int n,int k)
  {
      //Assuming counting is starting from 0 then base case will be
      if(n==1)
      {
          return 0;
      }
      
      //Calling remaining person for next round of killing person
      int remainingPersons=Josephus(n-1,k);
      
      //adjusting the postion for newly starting person 
      int personPosition=remainingPersons+k;
      
      //reducing the position of person so that position will not be greater than 
      //total numbers of pepoles persent in the circle.
      int personPosition=person%n;
      return personPosition;
  }
    int safePos(int n, int k) {
        //This problem is based on Josephus Problem
        
        int position=Josephus(n,k);
        
        //returning one more postion as Josephus function is counting initial position 
        //from 0
        
        return position+1;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends