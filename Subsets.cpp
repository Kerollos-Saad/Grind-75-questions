class Solution {
public:

    void recSubSets(vector<int>& nums, vector<vector<int>>& res, int idx = 0)
    {
        if(idx == nums.size())
            return;
        if(idx == 0){
            vector<int> x;
            res.push_back(x);
            vector<int>().swap(x);
        }

        int new_val = nums[idx];
        vector<vector<int>> sets;

        for(auto&it: res){
            vector<int> tmp = it;
            tmp.push_back(new_val);
            sets.push_back(tmp);
            vector<int>().swap(tmp);
        }

        for(auto&it: sets)
            res.push_back(it);

        vector<vector<int>>().swap(sets);

        recSubSets(nums, res, idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        recSubSets(nums, res);
        return res;
    }
};