/*leetcode 1328 Break a palindrome solved using GREEDY ALGORITHM*/
/*They give a palindrome input our task is to return the next lexicographically (mean's 1st preference alphabets) smallest string*/
/*Simple Approach (Step-by-Step)

If the string length is 1 → return empty string.
(Because any single character is always a palindrome, can’t break it.)

Loop through the first half of the string:

If you find a character that is not 'a', change it to 'a' and return.
(Why first half? → Because palindrome is symmetric, changing left side is enough.)

If all the first half are 'a':

Change the last character to 'b'.
(This ensures smallest lexicographic result and breaks the palindrome.) */
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int l = palindrome.size();
        
        // Case 1: If palindrome length <= 1, it's impossible to break
        if(l <= 1) return "";
        
        // Case 2: Iterate through the first half of the string
        for(int i = 0; i < l/2; i++) {
            if(palindrome[i] != 'a') {
                // Replace the first non-'a' character with 'a'
                palindrome[i] = 'a';
                return palindrome; // done, return smallest result
            }
        }
        
        // Case 3: If all characters in the first half are 'a'
        // Then change the last character to 'b' (to make it non-palindrome)
        palindrome[l-1] = 'b';
        return palindrome;
    }
};
