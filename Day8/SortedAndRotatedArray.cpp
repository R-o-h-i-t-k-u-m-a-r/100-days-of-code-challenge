//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    bool checkRotatedAndSorted(int arr[], int num){
        
        // Finding Min and Max of the array
        int Min=INT_MAX;
        int Max=INT_MIN;
        for(int i=0;i<num;i++)
        {
            Min=min(arr[i],Min);
            Max=max(arr[i],Max);
        }
        
        //Finding index of minimun element of the array
        int Index;
        for(int i=0;i<num;i++)
        {
            if(arr[i]==Min)
            {
                Index=i;
                break;
            }
        }
        
        //Finding index of Maximum element of the array
        int maxIndex;
        for(int i=0;i<num;i++)
        {
            if(arr[i]==Max)
            {
                maxIndex=i;
                break;
            }
        }
        
         //Validating either array is Sorted in increasing order or not
        bool isSorted=true;
        Index=Index+1;
        for(int i=1;i<num;i++)
        {
            if(arr[Index%num]<arr[(Index-1)%num])
            {
                isSorted=false;
                break;
            }
            Index++;
        }
        
        //If array is not sorted in increasing order then Validating either array is Sorted in decreasing order or not
         bool deSorted=true;
        if(isSorted==false)
        {
       
        maxIndex=maxIndex+1;
        for(int i=1;i<num;i++)
        {
            if(arr[maxIndex%num]>arr[(maxIndex-1)%num])
            {
                deSorted=false;
                return false;
            }
            maxIndex++;
        }
        }
        
        
        //Validating Array is Rotated is not 
        if(isSorted)
        {
            if(arr[0]==Min && arr[num-1]==Max)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if(deSorted)
        {
            if(arr[0]==Max && arr[num-1]==Min)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	//testcases
	cin>> T;
	
	while (T--){
	    int num;
	    //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        Solution ob;
        
        //function call
        flag = ob.checkRotatedAndSorted(arr, num);
        
        //printing "No" if not sorted and
        //rotated else "Yes"
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}
// } Driver Code Ends