//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        //Solving this problem with the help of two pointer approach
        //Assuming at the begining of tour our start and end position is same and we
        //don't have current petrol reserved
        int Front=0,Rear=0,index=0,currPetrol=0;
        bool Flag=true;
        
        //To complete circulat tour for all petrol pumps we need to visit at most two times
        //of each petrol pumps
        for(int i=0;i<2*n;i++){
            
            //to make circular we need to maintain postion of each petrol pumps
            index=i%n;
            
            //If we visit petrol pump that has sufficient fuel to reach next petrol pump
            if(p[index].petrol+currPetrol>=p[index].distance && Flag){
                
                //then we need to find how many reserved petrol we have for next petol pump
               currPetrol+=p[index].petrol-p[index].distance;
               
               //then move to next petrol pump
               Front=(Front+1)%n;
               
               //if we find our source and destination petrol pump then tour has been finish
               if(Front==Rear){
                   return Front;
               }
           }
           //if we find petrol pump that has sufficient fuel to reach next petrol pump
           //but we do not have any source and destination pumps then need to start from
           //this petrol pumps
           else if(p[index].petrol+currPetrol>=p[index].distance && !Flag){
              currPetrol+=p[index].petrol-p[index].distance;
               Front=Rear=index;
               Flag=true;
           }
           //if we find any petrol pumps that has not sufficient fuel then reset source
           //and destination petrol pump
           else{
               currPetrol=0;
               Flag=false;
           }
       }
       
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends