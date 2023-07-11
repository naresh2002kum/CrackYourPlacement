//sliding window
//o(n),  s.c->o(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int ans = 0;
        int total_sum = 0;
        
        int n = cardPoints.size();
        
        for(int i = 0; i < k; i++) {
            total_sum += cardPoints[i];
        }
        
        ans = max(ans, total_sum); // It may be possible to only include left side cards only
        
        for(int i = k - 1; i >= 0; i--) { // Gradually trying all possibilities
            total_sum -= cardPoints[i];
            total_sum += cardPoints[n - k + i];
            ans = max(total_sum, ans);
        }
        return ans;
    }
};