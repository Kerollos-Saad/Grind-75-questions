class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(auto& it: intervals){
            if(res.back()[1] >= it[0])
                res.back()[1] = max(res.back()[1], it[1]);
            else
                res.push_back(it);
        }
        return res;
    }
};