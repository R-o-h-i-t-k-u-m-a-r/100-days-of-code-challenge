//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm 
    void quickSort(int arr[], int low, int high)
    {
        //There should be more than one element to sort the array
        if(low<high)
        {
            //Finding index of pivot element with the help of Lomuto Partition 
            int pivotIndex=partition(arr,low,high);
            
            //Now sort the array before pivotIndex
            quickSort(arr,low,pivotIndex-1);
            
            //And sort the array after the pivotIndex
            quickSort(arr,pivotIndex+1,high);
        }
    }
    
    public:
    //Implementing Lomuto Partition
    int partition (int arr[], int low, int high)
    {
       int i=-1;
       for(int j=0;j<high;j++)
       {
           //If there is element which is smaller than pivot element then shift if to left
           if(arr[j]<=arr[high])
           {
               i=i+1;
               swap(arr[i],arr[j]);
           }
       }
       //After shifting all smaller elements to the left side then swap pivot element
       //with next to right most smallert element index
       swap(arr[i+1],arr[high]);
       
       //Finally return of pivot element index
       return i+1;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends