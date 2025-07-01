class Solution {
public:

    void recPermute(vector<int>& nums, vector<vector<int>>& res, int idx=0)
    {
        if(idx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx], nums[i]);
            recPermute(nums, res, idx+1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        recPermute(nums,res);        
        return res;
    }
};