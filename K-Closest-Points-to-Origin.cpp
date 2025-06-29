class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        map<double, vector<vector<int>>> mp;

        for(auto&it: points){
            double idx = (it[0] * it[0]) + (it[1] * it[1]);
            mp[idx].push_back(it);
        }

        vector<vector<int>> res;
        for(auto&it:mp){
            for(auto&itt:it.second){ 
                res.push_back(itt);
                k--;
                if(!k) break;
            }
            if(!k) break;
        }
        
        return res;
    }
};