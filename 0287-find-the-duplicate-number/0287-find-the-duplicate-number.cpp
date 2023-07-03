//t.c-o(n) ,s.c-o(1)
// have a time complexity of O(n) and a space complexity of O(1) by utilizing the Floyd's Tortoise and Hare algorithm.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        // Find the intersection point of the two pointers
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the start of the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};


 /*Explanation:
This optimized solution uses the concept of finding the cycle in a linked list. In this case, we treat the array nums as a linked list, where the indices represent the nodes and the values at the indices represent the next pointers.

The algorithm starts by initializing two pointers, tortoise and hare, both pointing to the first element of the array. Then, it enters a loop where the tortoise moves one step at a time and the hare moves two steps at a time. Eventually, they will meet at some point inside the cycle.

Once the meeting point is found, we reset the tortoise to the first element and keep the hare at the meeting point. Then, we move both pointers one step at a time until they meet again. The meeting point of the two pointers will be the start of the cycle, which corresponds to the duplicate element in the array.*/