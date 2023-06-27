//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        //Using hash map storing all the frequencies of array elements
        
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        
        //Now Storing all the arrays element along with their respective frequencies
        vector<pair<int,int>> v;
        for(auto ele:freq){
            pair<int,int> temp;
            temp.first = ele.first;
            temp.second = ele.second;
            v.push_back(temp);
        }
        
        //Now sorting vector element with repect to their frequecies with the help of 
        //comparator function
        sort(v.begin(),v.end(),comparator);
        
        //After sorting storing all the array element 
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            int temp=v[i].second;
            while(temp>0)
            {
                ans.push_back(v[i].first);
                temp--;
            }
            
        }
        
        return ans;
    }
    
    bool static comparator(pair<int,int> a, pair<int,int> b){
        
        if(a.second==b.second){
            return (a.first<b.first);
        }
        else{
            return (a.second>b.second);
        }
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends