class Solution {
  private:
    int func(int ind,int Pre_Ind,vector<int>& nums,int n, vector<vector<int>>&dp){
        //base case
        if(ind==n) return 0;

        if( dp[ind][Pre_Ind+1]!=-1) return dp[ind][Pre_Ind+1];

        int Len=0+func(ind+1,Pre_Ind,nums,n,dp);  //not take
 
        if(Pre_Ind==-1 ||nums[ind]>nums[Pre_Ind])

            Len=max(Len,1+func(ind+1,ind,nums,n,dp));

         return dp[ind][Pre_Ind+1]=Len;   
    }  
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0,-1,nums,n,dp);    //start from func(0,-1)
    }
};