// Problem Link: https://leetcode.com/problems/count-vowels-permutation/

// INTUITION: The question is easy, from the vowels, we have to count all possible strings that can be 
// formed using 'a','e','i,'o,'u' of length n.
// Which should follow the below rules.
// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

// SO from the above conditions we can observe that we have many options available with us.
// The below code makes it understand.

// Since we have to make string by taking 1 character as vowel, we will run loop for taking every vowel
// and then generate count.
class Solution {
public:
    const int MOD = 1e9+7;
    int dp[26][20001];
    int solve(char ch, int n)
    {
        if(n == 0) return 1;
        
        if(dp[ch-'a'][n] != -1) return dp[ch-'a'][n];
        int res = 0;
        if(ch == 'a')
        {
            res = (res%MOD + solve('e' , n-1)%MOD)%MOD;
        }
        else if(ch == 'e')
        {
            res = (res%MOD + solve('a', n-1)%MOD)%MOD;
            res = (res%MOD + solve('i', n-1)%MOD)%MOD;
        }
        else if(ch == 'i')
        {
            res = (res%MOD+ solve('a', n-1)%MOD)%MOD;
            res = (res%MOD +  solve('e' , n-1)%MOD)%MOD;
            res = (res%MOD + solve('o', n-1)%MOD)%MOD;
            res = (res%MOD + solve('u', n-1)%MOD)%MOD;
        }
        else if(ch == 'o')
        {
            res = (res%MOD + solve('i', n-1)%MOD)%MOD;
            res = (res%MOD + solve('u', n-1)%MOD)%MOD;
        }
        else
        {
            res = (res%MOD + solve('a', n-1)%MOD)%MOD;
        }

        return dp[ch-'a'][n] = res;
    }
    int countVowelPermutation(int n) {
          string s = "aeiou";
          int res= 0 ;
          memset(dp, -1, sizeof dp);
          for(int i= 0 ; i < 5 ; i++)
          {
             res= (res%MOD +  solve(s[i], n-1)%MOD)%MOD;
            
          }

          return res;
    }
};