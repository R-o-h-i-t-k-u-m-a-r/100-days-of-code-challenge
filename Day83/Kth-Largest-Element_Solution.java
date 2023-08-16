//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class gfg {
    public static void main(String args[]) {
        
        //taking input using class Scanner
        Scanner sc = new Scanner(System.in);
        
        //taking count of testcases
        int t = sc.nextInt();

        while (t-- > 0) {
            
            //taking count of elements
            int n = sc.nextInt();
            
            //taking the value of k
            int k = sc.nextInt();

            //Creating an array of size n
            int arr[] = new int[n];

            //adding all the elements to arr
            for (int i = 0; i < n; ++i) arr[i] = sc.nextInt();

            //calling the method KthLargest of class solve
            //and printing the result
            System.out.println(new Solution().KthLargest(arr, n, k));
        }
    }
}
// } Driver Code Ends




class Solution 
{
    //Function to return kth largest element from an array.
    public static int KthLargest(int arr[], int n, int k) 
    {
        //implementing MinHeap using priority queue.
        Queue<Integer> minHeap=new PriorityQueue<>();
        for (int i = 0; i < n; i++) 
        {
            //if size of priority queue becomes equal to k and top 
            //element is smaller than arr[i], we pop the front 
            //element and push arr[i] in priority queue.
            if (minHeap.size() == k && minHeap.peek() < arr[i]) 
            { 
                minHeap.poll();
                minHeap.offer(arr[i]);
            } 
            //else we just push arr[i] in priority queue.
            else if (minHeap.size() < k)
                minHeap.offer(arr[i]);
        }
        //returning the top element of priority queue.
        return minHeap.peek(); 
    }
}