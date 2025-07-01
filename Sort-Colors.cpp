class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto&it:nums)
            mp[it]++;
        int idx = 0;
        for(auto&it:mp)
            for(int i=0;i<it.second;i++)
                nums[idx++] = it.first;
        
    }
};