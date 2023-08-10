// GFG Link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii

// Intuition :  Why are we even using useonLevels array and vec array and 
// unordered_set. 

//  Dekho initially hamara level 0 matlab ham always previous level
//  ka track rakh rhe hai, 
// initially queue me StartWord push hua and uske pehle previous level 0
// hai. 
// and usedOnLevels ka kaam ye hai ki jab ham 'L' length ke saare list
//  banate waqt un words ko usedOn Levels array me push kr dete hai, taaki
// jab saare 'L' length ke list ban jaaye to ham useOnLevels traverse
// krke un words ko set se erase kr paaye.

// vec array ka kaam ye hai ki usko queue me push krna hai
// suppose StartWord = 'dog' hai , and maine isko, pehle 'cog' me 
//  transform kiya to so vec  = {dot , cog};
// but ye one of the possible transformation hai so, hum again 
// vec.pop_back() se pop karenge and dusra possible transformation 
// banaayenge , eg: vec = {dot , dot}.

// And jaise hi hum ab length 3 ke list banaayenge, then ham cog and dot
// ko set me se erase kr degne with the help of usedOnLevel array.

// Note: We will only erase from the set if all the 'L' length lists
// have been made.




class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        // Here we are storing a list of string s.
        queue<vector<string>> q;
        vector<vector<string>> ans;
        
        q.push({beginWord});
        unordered_set<string> s(wordList.begin() , wordList.end());
        int level = 0;
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        
        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            
            // erase all words that has been used on preivous level to transform
            if(vec.size() > level )
            {
                level++;
                
                for(auto elem : usedOnLevel)
                {
                    s.erase(elem);
                }
                
                usedOnLevel.clear();
            }
             

        string word = vec.back();
            
            if(word ==  endWord)
            {
                if(ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size()== vec.size())
                {
                    ans.push_back(vec);
                }
            }
            
            for(int i =0 ; i < word.size() ; i++)
            {
                char original = word[i];
                
                for(char ch = 'a' ; ch <= 'z' ; ch++)
                {
                    word[i] = ch;
                    
                    if(s.count(word) > 0)
                    {
                        usedOnLevel.push_back(word);
                        vec.push_back(word);
                        q.push(vec);
                        
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
            
            
            
        }
        
        return ans;
        
        
    }
};