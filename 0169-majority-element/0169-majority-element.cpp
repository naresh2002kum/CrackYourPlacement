//MOORE voting algorithm
//optimal approach, t.c-o(n) ,s.c-1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int element;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                element=nums[i];
            }else if(nums[i]==element){
                cnt++;
            }else{
                cnt--;
            }
        }
        
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element){
                cnt1++;
            }
            if(cnt1>n/2)
                return element;
        }
        return -1;
        
    }
};