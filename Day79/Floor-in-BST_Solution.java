//{ Driver Code Starts
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

    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            int x = Integer.parseInt(br.readLine());
            Sol obj = new Sol();
            System.out.println(obj.floor(root, x));
            t--;
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Sol {
    // Function to return the floor of given number in BST.
    int floor(Node root, int key) {
        //if BST has no node then floor will be -1
        if(root==null)
        {
            return -1;
        }
        //Assuming initially floor value of given key is -1
        int floor=-1;
        
        //Impleming BST Search to find floor of given number
        while(root!=null){
            
            //if given numer is found then return the current node data
            if(root.data==key) return root.data;
            
            //if current node is less then the given number then we store node as floor 
            //and will search in right subtree so that we could get immediate sammler value
            else if(root.data<key){
                floor=root.data;
                root=root.right;
            }
            
            //if given number is less then current node data then need to search in 
            //left subtree so that we could get smaller value then given key 
            else root=root.left;
        }
        
        //After BST search return our floor value 
        return floor;
    }
}
