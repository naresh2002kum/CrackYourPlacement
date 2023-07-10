class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          int n = nums.size();
        int cnt = 0;
        unordered_map<int, int>mp; //fre,sum
        int sum = 0;
        mp[0]++;
        for (auto x:nums) {
          sum+=x;

          if(mp[(sum%k+k)%k]>0){ //to handle negative number
              cnt+=mp[(sum%k+k)%k];
          }
          mp[(sum%k+k)%k]++;
        }
        return cnt;
    }
};