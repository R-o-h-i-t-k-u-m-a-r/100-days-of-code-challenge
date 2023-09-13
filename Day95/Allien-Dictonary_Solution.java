//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = Integer.parseInt(sc.next());
		while(t-- > 0)
		{
		    int n = Integer.parseInt(sc.next());
		    int k = Integer.parseInt(sc.next());
		    
		    String[] words = new String[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        words[i] = sc.next();
		    }
		    
		    Solution ob = new Solution();
		  //  System.out.println(T.findOrder(words,k));
		    String order = ob.findOrder(words,n,k);
		    if(order.length() == 0){
		        System.out.println(0);
		        continue;
		    }
		    String temp[] = new String[n];
		    for(int i=0;i<n;i++)
		        temp[i] = words[i];
		    
		    Arrays.sort(temp, new Comparator<String>(){
		    
		      @Override
                public int compare(String a, String b) {
                    int index1 = 0;
                    int index2 = 0;
                    for(int i = 0; i < Math.min(a.length(), b.length()) 
                                        && index1 == index2; i++) {
                        index1 = order.indexOf(a.charAt(i));
                        index2 = order.indexOf(b.charAt(i));
                    }
                
                    if(index1 == index2 && a.length() != b.length()) 
                    {
                        if(a.length() < b.length())
                            return -1;
                        else
                            return 1;
                    }
                
                    if(index1 < index2)
                        return -1;
                    else
                        return 1;
                        
                }
		    });
		    
		    int flag = 1;
		    for(int i=0;i<n;i++)
		    {
		        if(!words[i].equals(temp[i]))
	            {
	                flag = 0;
	                break;
	            }
		    }
		    
		    System.out.println(flag);
		}
	}
	
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public String findOrder(String [] dict, int N, int K)
    {
        //Solving thip problem using Topological sorting technique
        //Creating adjacency list from given dictonary by comparing pair string with their first
        //distinct chartacter
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<K;i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i=0;i<N-1;i++){
            //taking two string at time to compare each character
            String s1=dict[i];
            String s2=dict[i+1];
            //compare both string till the smallest length of string
            int len=Math.min(s1.length(),s2.length());
            
            for(int ch=0;ch<len;ch++){
                //if any char found distinct then no need to check for other's
                if(s1.charAt(ch)!=s2.charAt(ch)){
                    //storing all character's into number's
                    adj.get(s1.charAt(ch) - 'a').add(s2.charAt(ch) - 'a');
                    break;
                }
            }
        }
        //Using topological sorting getting all the sequence of character's
        List<Integer> topo=TopoSort(K,adj);
        String ans="";
        for(int it:topo){
            //converting number's back to character's form
            ans+=(char)(it + (int)('a'));
        }
        
        return ans;
        
    }
    
    List<Integer> TopoSort(int V,List<List<Integer>> adj){
        
        int indegree[]=new int[V];
        
        for(int i=0;i<V;i++){
            for(int it:adj.get(i)){
                indegree[it]++;
            }
        }
        
        Queue<Integer> q=new LinkedList<Integer>();
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.add(i);
            }
        }
        
        List<Integer> topo=new ArrayList<Integer>();
        while(q.isEmpty()==false){
            int node=q.peek();
            q.remove();
            topo.add(node);
            for(int it:adj.get(node)){
                indegree[it]--;
                if(indegree[it]==0){
                    q.add(it);
                }
            }
        }
        
        return topo;
    }
}