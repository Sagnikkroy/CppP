#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int>& nums) {
    // STEP 1: Initialize variables
    int candidate = nums[0];  // Start with first element as potential candidate
    int votes = 1;            // First element gets 1 vote
    
    // STEP 2: First Pass - Find potential majority candidate
    // Loop through all elements starting from second one
    for(int i = 1; i < nums.size(); i++) {
        // If current element matches our candidate
        if(nums[i] == candidate) {
            votes++;  // Increase votes for candidate
        }
        // If current element is different from candidate
        else {
            votes--;  // Cancel one vote
            
            // If votes become 0, choose new candidate
            if(votes == 0) {
                candidate = nums[i];  // New candidate
                votes = 1;            // Reset votes to 1 for new candidate
            }
        }
    }
    
    // STEP 3: Second Pass - Verify the candidate actually appears more than n/2 times
    // (This step is necessary because algorithm might find a candidate even if no majority exists)
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == candidate) {
            count++;
        }
    }
    
    // STEP 4: Check if candidate is truly majority
    if(count > nums.size() / 2) {
        return candidate;
    } else {
        return -1;  // No majority element found
    }
}