class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        // First, separate positive and negative numbers
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                pos.push_back(nums[i]);  // Add to pos vector
            } else {
                neg.push_back(nums[i]);  // Add to neg vector
            }
        }
        
        // Then interleave them (positive first, then negative)
        int p = 0, n = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) {
                nums[i] = pos[p++];  // Take from positive array
            } else {
                nums[i] = neg[n++];  // Take from negative array
            }
        }
        
        return nums;
    }
};