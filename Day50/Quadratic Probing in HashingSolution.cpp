//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
    {
        
        //Let's create a variable which will track hashTable capacity
        int hashCap=0;
        
        //Initialize hash table with -1
        for(int i=0;i<hashSize;i++)
        {
            hash.push_back(-1);
        }
        //Now iterate to given array to insert each element into hash table
        for(int i=0;i<N;i++){
            
            //if hash table has no slot to insert key then stop inserting process
            if(hashSize==hashCap){
                break;
            }
            
            int key=arr[i];
            
            //Finding index of hash table with the help of hash funtion
            int index=key%hashSize;
            
            //if there is a collision with key index then search for , search for i2 
            //empty position.
            int count=0;
            while(hash[index]!=-1 && hash[index]!=key){
                count=count+1;
                index=(key+(count*count))%hashSize;
            }
            
            //if we found duplicate key then no need to insert
            if(hash[index]==key){
                continue;
            }
            else{
                //if we fond empty slot then insert element and increase hashCap variable
                //by one to track the hash table size
                hash[index]=key;
                hashCap++;
            }
        }
        
    }


};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize,-1);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}



// } Driver Code Ends