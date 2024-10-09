class Solution {
public:
    // Function to count subarrays with exactly K distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array
        int left_far = 0;    // This will track the left pointer for counting valid subarrays
        int left_near = 0;   // This will track the left pointer while adjusting the count of distinct numbers
        int right = 0;       // This will track the right pointer as we expand the window
        int cnt = 0;         // Count of valid subarrays found
        map<int,int>mp;      // Map to store the frequency of elements in the current window

        while(right < n) {
            // Add the current number to the frequency map
            mp[nums[right]]++;
            right++; // Move the right pointer to expand the window

            // While we have more than K distinct numbers in the window
            while(mp.size() > k) {
                // Decrease the frequency of the number at left_near pointer
                mp[nums[left_near]]--;

                // If frequency becomes zero, remove it from the map
                if(mp[nums[left_near]] == 0) {
                    mp.erase(nums[left_near]);
                }
                // Move the left_near pointer to the right
                left_near++;
                left_far = left_near; // Update left_far to keep track of valid subarrays
            }

            // While the number at left_near has frequency greater than 1
            while(mp[nums[left_near]] > 1) {
                // Decrease its frequency
                mp[nums[left_near]]--;
                // Move the left_near pointer to the right
                left_near++;
            }

            // If we have exactly K distinct numbers in the current window
            if(mp.size() == k) {
                // Count the number of valid subarrays ending at 'right - 1'
                cnt += left_near - left_far + 1;
            }
        }

        return cnt; // Return the total count of valid subarrays
    }
};
