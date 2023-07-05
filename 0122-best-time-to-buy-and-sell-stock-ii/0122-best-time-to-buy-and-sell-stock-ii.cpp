//space memoization 
//t.c-o(n)
//s.c-o(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();  

    vector<long> ahead (2,0);
    vector<long> cur(2,0);
    
    //base condition
    ahead[0] = ahead[1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+ahead[0], -prices[ind] + ahead[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+ahead[1], prices[ind] + ahead[0]);
            }
            cur[buy]  = profit;
        }
        
        ahead = cur;
    }
    return cur[0];
        
    }
};