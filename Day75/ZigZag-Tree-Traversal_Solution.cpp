//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.util.HashMap;
import java.io.*;

    class Node
    {
        int data;
        Node left,right;
        Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
    }
		
public class GFG2
{
    static Node buildTree(String str){
        
        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }
        
        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue
        
        Queue<Node> queue = new LinkedList<>(); 
        
        queue.add(root);
        // Starting from the second element
        
        int i = 1;
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    
	public static void inorder(Node root)
	{
	    if(root==null)
	    return;
	    inorder(root.left);
	    System.out.print(root.data);
	    inorder(root.right);
	}
     /* Drier program to test above functions */
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
    
	        while(t > 0){
	            String s = br.readLine();
    	    	Node root = buildTree(s);
        	    GFG g = new GFG();
			
			    ArrayList<Integer> res = g.zigZagTraversal(root) ;
			    for (int i = 0; i < res.size (); i++)
			        System.out.print (res.get (i) + " ");
			    System. out. println();  
    			
                t--;
            
        }
	}
}
// } Driver Code Ends


//User function Template for Java

/*class Node
{
    int data;
    Node left,right;
    Node(int d)
    {
        data=d;
        left=right=null;
    }
}*/

class GFG
{
    //Function to store the zig zag order traversal of tree in a list.
	ArrayList<Integer> zigZagTraversal(Node root)
	{
	    //To solve this poblem we are going to use Tree Level Order Traversal concept 
	    //but instead of queue container we will use two stacks here to traverse ZigZag
	    
	    ArrayList<Integer> ans= new ArrayList<Integer>();
	    
	    //If root node is empty the we need to return empty list
	    if(root==null){
	        return ans;
	    }
	    
	    //Creating First Stack which will store nodes from right to left order
	    Stack<Node> currentLevel = new Stack<Node>();
	    
	    //Creating Second Stack which will store nodes from left to right order
	    Stack<Node> nextLevel = new Stack<Node>();
	    
	    //Inserting first root node to currentLevel
	    currentLevel.push(root);
	    
	    //Traversing tree untill both stacks get empty
	    while(!currentLevel.isEmpty() || !nextLevel.isEmpty()){
	        
	        //If our currentLevel stack is not emtpy
	        while(!currentLevel.isEmpty()){
	            //Storing the top of stack and deleting as well
	            Node curr = currentLevel.pop();
	            //Store current node data into list
	            ans.add(curr.data);
	            //if current node has left chile then push into nextLevel stack
	            if(curr.left!=null) nextLevel.push(curr.left);
	            //if current node has right child then push into nextLevel stack
	            if(curr.right!=null) nextLevel.push(curr.right);
	        }
	        
	        //If our nextLevel stack is not empty
	        while(!nextLevel.isEmpty()){
	            //storing the top of stack and deleting as well
	            Node curr = nextLevel.pop();
	            //Store current node data into list
	            ans.add(curr.data);
	            //if current node has right child then push it into currentLevel stack
	            if(curr.right!=null) currentLevel.push(curr.right);
	            //if current node has left child then push it into currentLevel stack
	            if(curr.left!=null) currentLevel.push(curr.left);
	        }
	    }
	   
	   return ans;
	}
}