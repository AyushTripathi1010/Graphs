// GFG Link : https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder

// INTUITION: The question wants us to transform startWord to targetWord
//  in shortest steps possible using the words in wordList array.
class Solution {
public:

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>> q;
        
        // We are storing the worlist into set, so that once a word has been 
        // used we can erase it from the set in O(1) time. 
        unordered_set<string> s(wordList.begin() , wordList.end());
        
        q.push({startWord , 1});
        
        // Erasing from the set after getting the word once.
         s.erase(startWord);
         
         while(!q.empty())
         {
             string word = q.front().first;
             int len = q.front().second;
             q.pop();
             
             if(word == targetWord) return len;
             
             for(int i =0 ; i < word.size() ; i++)
             {
                 char original = word[i];
                 
                 for(char it = 'a' ; it<= 'z' ; it++)
                 {
                     word[i] = it;
                     if(s.find(word) != s.end())
                     {
                         s.erase(word);
                         q.push({word , len+1 });
                         
                     }
                 }
                 word[i] = original;
                 
             }
         }
         
         return 0;
        
        
    }
};