//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String[] wordList = new String[n];
            for(int i = 0; i < n; i++){
                wordList[i] = br.readLine().trim();
            }
            String startWord, targetWord;
            startWord = br.readLine().trim();
            targetWord = br.readLine().trim();
            Solution obj = new Solution();
            int ans = obj.wordLadderLength(startWord, targetWord, wordList);
            System.out.println(ans);
       }
    }
}

// } Driver Code Ends


class Pair{
    String first;
    int second;
    Pair(String _first,int _second){
        this.first=_first;
        this.second=_second;
    }
}
class Solution
{
    public int wordLadderLength(String startWord, String targetWord, String[] wordList)
    {
        //Solving this problem using BFS traversal 
        //Creating a queue which will hold word and transformation distance
        Queue<Pair> q=new LinkedList<>();
        
        //Inserting startword into queue at distance 1
        q.add(new Pair(startWord,1));
        
        //Inserting all the wordlist into hash set for making deleting and accessing 
        //cost minimum
        Set<String> st=new HashSet<>();
        int len=wordList.length;
        for(int i=0;i<len;i++){
            st.add(wordList[i]);
        }
        
        //Removing the startWord from hashset which is initially inserted into queue
        st.remove(startWord);
        
        //Implementing BFS Traversal
        while(q.isEmpty()==false){
            String word=q.peek().first;
            int steps=q.peek().second;
            q.remove();
            
            //If we found first occurance of targetword then will return the steps
            if(word.equals(targetWord)==true) return steps;
            
            // Now, replace each character of ‘word’ with char
            // from a-z then check if ‘word’ exists in wordList.
            for(int i=0;i<word.length();i++){
                for(char ch='a';ch<='z';ch++){
                    char replacedCharArray[] = word.toCharArray();
                    replacedCharArray[i] = ch;
                    String replacedWord = new String(replacedCharArray);
                    
                      // check if it exists in the set and push it in the queue.
                      if (st.contains(replacedWord) == true){
                          st.remove(replacedWord);
                           q.add(new Pair(replacedWord, steps + 1));
                      }
                }
            }
        }
        
        //If there is no transition sequence possible 
        return 0;
    }
}