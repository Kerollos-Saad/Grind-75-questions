class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> ump;

        for(int i=0; i<nums.size() ; i++)
        {
            int complement = target - nums[i];
            if(ump.find(complement)!=ump.end())
            {
                return {i, ump[complement]};
            }
            ump[nums[i]] = i;
        }

        
        return {};
    }
};