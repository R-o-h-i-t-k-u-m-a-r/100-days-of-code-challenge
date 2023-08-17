//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class gfg
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int num = sc.nextInt();
            int k = sc.nextInt();
            
            int arr[] = new int[num];
            for(int i = 0; i < num; i++)
                arr[i] = sc.nextInt();
            
            ArrayList <Integer> res = new Solution().nearlySorted(arr, num, k);
            for (int i = 0; i < res.size (); i++)
                System.out.print (res.get (i) + " ");
            System.out.println();
        }
    }
}


// } Driver Code Ends


class Solution
{
    //Function to return the sorted array.
    ArrayList <Integer> nearlySorted(int arr[], int num, int k)
    {
        ArrayList <Integer> res = new ArrayList <Integer> (0);
        
        //implementing MinHeap using priority queue and 
        //storing first k elements in it.
        Queue<Integer> pq = new PriorityQueue<>();
        for(int i = 0; i<=k; ++i)
            pq.add(arr[i]);
               
        for(int i = k+1; i < num; i++)
        {
            //storing top element from priority queue in list and popping it.
            res.add(pq.peek());
            pq.poll();
            
            //pushing the current array element in priority queue.
            pq.add(arr[i]);
        }
        
        //using a loop till priority queue becomes empty.       
        while(!pq.isEmpty())
        {
            //storing top element from priority queue in list and popping it.
            res.add(pq.peek());
            pq.poll();
        }
        //returning the list.
        return res;
    }
}
