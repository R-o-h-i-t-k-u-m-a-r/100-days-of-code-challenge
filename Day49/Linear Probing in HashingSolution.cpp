//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        //Creating a a Hash Table which will store unique keys
        vector<int> v;
        
        //Let's create a variable which will track hashTable capacity
        int hashCap=0;
        
        //Initialize hash table with -1
        for(int i=0;i<hashSize;i++)
        {
            v.push_back(-1);
        }
        //Now iterate to given array to insert each element into hash table
        for(int i=0;i<sizeOfArray;i++){
            
            //if hash table has no slot to insert key then return hash table
            if(hashSize==hashCap){
                return v;
            }
            
            int key=arr[i];
            
            //Finding index of hash table with the help of hash funtion
            int index=key%hashSize;
            
            //if there is a collision with key index then search for immediate next 
            //empty position
            while(v[index]!=-1 && v[index]!=key){
                index=(index+1)%hashSize;
            }
            
            //if we found duplicate key then no need to insert
            if(v[index]==key){
                continue;
            }
            else{
                //if we fond empty slot then insert element and increase hashCap variable
                //by one to track the hash table size
                v[index]=key;
                hashCap++;
            }
        }
        
        return v;
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
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    Solution obj;
	    hash = obj.linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}


// } Driver Code Ends