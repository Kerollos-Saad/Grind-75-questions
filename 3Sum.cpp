class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        int s = nums.size();

        for(int i=0; i<s-2; i++){

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int mid=i+1, heigh=s-1;
            
            while(mid < heigh){
                int val = nums[i] + nums[mid] + nums[heigh];
                if(val == 0)
                {
                    res.push_back({nums[i], nums[mid], nums[heigh]});
                    mid++;
                    heigh--;
                    while(mid < heigh && nums[mid] == nums[mid - 1]) mid++;
                    while(mid < heigh && nums[heigh] == nums[heigh + 1]) heigh--;
                }
                else if(val > 0)
                    heigh--;
                else 
                    mid++;
            }
        }
        return res;
    }
};