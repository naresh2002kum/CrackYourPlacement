class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=0;
       int k=0;
       int j=0;
       int temparr[m+n];

       while(i<m && j<n){
           if(nums1[i]<nums2[j]){
               temparr[k]=nums1[i];
               i++;
               k++;
           }else{
               temparr[k]=nums2[j];
               j++;
               k++;
           }

       } 
       while(i<m){
           temparr[k]=nums1[i];
           i++;
           k++;
       }
       while(j<n){
           temparr[k]=nums2[j];
           j++;
           k++;
       }

       
       for(int i=0;i<(m+n);i++){
           nums1[i]=temparr[i];
       }
    }
};