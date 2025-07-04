class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res = 0;
        int l = 0, r = height.size()-1;

        while(l < r)
        {
            int water = (r-l) * min(height[l], height[r]);
            res = max(res, water);

            if(height[l] < height[r]) 
                l++;
            else 
                r--;
        }
        return res;
    }
};