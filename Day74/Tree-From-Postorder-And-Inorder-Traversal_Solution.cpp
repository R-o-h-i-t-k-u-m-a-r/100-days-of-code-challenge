//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

class InorderPostorderToTree {
    public void preOrder(Node root) {
        if (root == null) return;

        System.out.print(root.data + " ");
        preOrder(root.left);

        preOrder(root.right);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        InorderPostorderToTree ip = new InorderPostorderToTree();
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int inorder[] = new int[n];
            int postorder[] = new int[n];
            for (int i = 0; i < n; i++) inorder[i] = sc.nextInt();
            for (int i = 0; i < n; i++) postorder[i] = sc.nextInt();
            GfG g = new GfG();
            Node root = g.buildTree(inorder, postorder, n);
            ip.preOrder(root);
            System.out.println();

            T--;
        }
    }
}

// } Driver Code Ends


/* Tree node structure
class Node
{
    int data;
    Node left;
    Node right;

        Node(int value)
    {
        data = value;
        left = null;
        right = null;
    }
}*/


class GfG
{
    //Function to return a tree created from postorder and inoreder traversals.
    static int index;
    Node buildTree(int in[], int post[], int n) {
        //Initialize index for post order traversal array
        index=n-1;
        
        return buildTreeImpl(in,post,0,n-1);
    }
    
    Node buildTreeImpl(int in[],int post[],int start,int end){
        //our base case will be when start and end index of indorder will cross each other
        //then we need to make null that node and return
        if(start>end){
            return null;
        }
        
        //Creating node of by taking last value of postorder traversal and reducing array
        //index as well
        Node node=new Node(post[index--]);
        
        //if we found that our start and end index is same it means their will be a node with
        //no child nodes
        if(start==end){
            return node;
        }
        
        int valueIndex=0;
        //searching the node position in inorder traversal array linearly
        for(int i=start;i<=end;i++){
            if(in[i]==node.data){
                valueIndex=i;
                break;
            }
        }
        //since we have given postorder traversal so we need to add right child first 
        //then left child to make proper tree and then return the root node
        node.right=buildTreeImpl(in,post,valueIndex+1,end);
        node.left=buildTreeImpl(in,post,start,valueIndex-1);
        
        return node;
    }
}
