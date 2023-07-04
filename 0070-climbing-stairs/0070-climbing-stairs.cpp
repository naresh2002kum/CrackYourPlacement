class Solution {
// private:
//  long long int func(int ind){
//    //base case
//     if(ind==0)
//      return 1;

//     if(ind==1)
//      return 1;

//     long long int left=func(ind-1);
//     long long int right=func(ind-2);

//  return left+right;
//  }    
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        // dp[0] = 1 and dp[1] = 1 means that there is only one 
        // distinct way to reach the first and second steps of the stairs.
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
