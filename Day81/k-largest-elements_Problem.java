//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;


class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t > 0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            
            int arr[] = new int[n];
            for(int i = 0; i<n; ++i)
                arr[i] = sc.nextInt();
            Solution ob = new Solution();
            ArrayList<Integer> list = ob.kLargest(arr, n, k);
            for(int i = 0; i<list.size(); i++)
                System.out.print(list.get(i) + " ");
            System.out.println();
            t--;
        }
    }
}



// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to return k largest elements from an array.
    public static ArrayList<Integer> kLargest(int arr[], int n, int k)
    {
        //implementing MinHeap using priority queue.
        Queue<Integer> q = new PriorityQueue<Integer>();
        
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++)
        {
            //if size of priority queue becomes equal to k,
            if(q.size() == k) 
            { 
                //if top element is smaller than arr[i], we pop the front 
                //element from priority queue and push arr[i] in priority queue.
                if(q.peek() < arr[i]) 
                {
                    q.poll();
                    q.add(arr[i]);
                }
            } 
            //else we just push arr[i] in priority queue.
            else 
            {
                q.add(arr[i]);
            }
        }
        
        //while priority queue is not empty, we keep storing the top element 
        //in list and keep popping it from the priority queue.
        while(!q.isEmpty())
        {
            list.add(q.peek()); 
            q.poll();
        }
        //reversing the list and returning it.
        Collections.reverse(list);
        return list;
    }
}