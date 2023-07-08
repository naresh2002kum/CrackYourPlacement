class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> prefixSums;
        int sum = 0;
        prefixSums[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (prefixSums.find(sum - k) != prefixSums.end()) {
                count += prefixSums[sum - k];
            }
            prefixSums[sum]++;
        }
        return count;
    }
};

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
