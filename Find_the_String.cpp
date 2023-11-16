// Problem Link: https://www.geeksforgeeks.org/problems/find-the-string/1

// INTUITION: Here the question asks us to generate a minimum possible length string, which constains all the possible strings of length N, as substring
// The characters used in the string are from 0 to k-1.
// Input:
// N = 2, K = 3
// Output: 
// 0010211220
// Explanation: 
// Allowed characters are from 0 to k-1 (i.e., 0, 1 and 2).
// There are total 9 strings possible
// of size N, given output string has the minimum
// length that contains all those strings as substring.

// So if take a look at all possible substrings that can be formed from 0,1,2 of length N = 2 are: "00", "01", "02", "10", "11", "12", "20", "21", "22"
// These are the 9 strings that can be formed, and in the output we can see that all these 9 strings are present.

// TO make this output we can do simple dfs, for each position, so for each position i, will try every character from 0 to k-1 and then see whether that 
// string is present in my set or not.
// If that string is present then i will decrement my loop counter, and then try for 1, ans then similalry for 0.
// If i have encountered the string 1st time i will insert it into set, and also push the character that i have appended right now, in my ans string, which
// is the final string.

// Initially, I have pushed allo character 0 till length N, so that on calling dfs, i will have to return ony the first character from the string and just append
// 1 character from 0 to k-1, just like sliding window.

// SO the loop is used for trying all character from 0 to k-1.
// And dfs call is used to insert 2 or k-1 again and again at new position, basically dfs is used for appending on new position.


// temp string is used to maintain and slice the first character, while the ans string stores the real output.

class Solution
{
public:
    unordered_set<string> s;
    void dfs(string &curr , string &ans , int n,  int k)
    {
        // to remove the first character
        // string temp = curr.substr(1);
        // OR
        string temp = curr.erase(0,1);
        
        for(int i = k-1; i>=0; i--) // we can start loop from 0 to k also doesn't matter
        {
            string t = temp + char(i+'0');
            
            if(!s.count(t))
            {
                s.insert(t);
                ans = ans + char(i+'0');
                
                dfs(t , ans, n, k);
                return;
            }
        }
    }
    string findString(int n, int k) {
          
          
          string temp="";
          string ans="";
          for(int i= 0 ; i < n ; i++)
          {
              temp+= '0';
              
          }
          s.insert(temp);
          ans = temp;
          
          dfs(temp, ans, n, k);
          
          return ans;
    }
};