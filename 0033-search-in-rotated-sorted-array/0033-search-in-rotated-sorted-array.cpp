class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int ind;
        // if(nums[0] <= nums[nums.size()-1]){

        // }
int s=0;
int e=nums.size()-1;
while(s<=e){
int m=(e+s)/2; //divide by 2
if(nums[m]==target){
    return m;
}
//chech either left side is sorted
if(nums[s]<=nums[m]){
    //check if element lies on left half or not
    if(target>=nums[s]&& target<=nums[m]){
        e=m-1;
    }
    else{
        s=m+1;
    }
}
//right side is sorted
else{
    if(target>=nums[m] && target<=nums[e]){
        s=m+1;
    }else{
        e=m-1;
    }
}
}
return -1;   
}
};