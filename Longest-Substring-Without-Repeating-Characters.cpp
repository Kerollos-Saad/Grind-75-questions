class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> ump;
                
        int mx = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            ump[c] = ump[c] + 1;
            
            while (ump[c] > 1) {
                char leftChar = s[left];
                ump[leftChar] = ump[leftChar] - 1;
                left++;
            }
            
            mx = max(mx, right - left + 1);
        }
        
        return mx;
    }
};