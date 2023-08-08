//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
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
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }
    static void printInorder(Node root) {
        if (root == null) return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String s = br.readLine();
            int x = Integer.parseInt(br.readLine());
            Node root = buildTree(s);
            Tree g = new Tree();
            root = g.deleteNode(root, x);
            printInorder(root);
            System.out.println();
            t--;
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Tree {
    // Function to delete a node from BST.
    public static Node deleteNode(Node root, int X) {
        //if key is not present in BST then we need to return tree
        if(root==null) return root;
        
        //if key is present then we first do BST Search to know the key position in tree
        else if(root.data>X) root.left=deleteNode(root.left,X);
        else if(root.data<X) root.right=deleteNode(root.right,X);
        
        //if key is found then we check either it is leaf node or having one or two child
        else{
            //if key node is leaf node or having one child at right side then we need to 
            //link its right child to privous node then releas key node
            if(root.left==null) return root.right;
            
            //if key node is leaf node or having one child at left side then we need to 
            //link its left child to privous node then release key node 
            else if(root.right==null) return root.left;
            
            //if key node has two leaf node then we need to find its smallest largest 
            //key node at right subtree for deletion purpose
            else{
                //finding smallest largest key node at right subtree
                Node smallestGreatestNode=getNode(root);
                
                //after getting smallest greatest node we need to override key node
                //data to smallest greatest node then we will simply delte the 
                //smallest greatest node at right side 
                root.data=smallestGreatestNode.data;
                root.right=deleteNode(root.right,root.data);
            }
        }
        return root;
    }
    //Method to find smallest greatest node at right sub tree of root node
    public static  Node getNode(Node root){
        root=root.right;
        while(root!=null && root.left!=null){
            root=root.left;
        }
        return root;
    }
}