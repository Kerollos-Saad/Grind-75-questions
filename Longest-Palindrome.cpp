class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        for(auto&it:s)
            mp[it]++;
        for(auto&it:mp)
            res += (int)(it.second/2)*2;
        
        return (res==s.size() ? res : res+1); 
    }
};