class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {  // Negative numbers cannot be palindromes
        return false;
    }
    
    string str = to_string(x);  // Convert integer to string
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true; 
    }
};