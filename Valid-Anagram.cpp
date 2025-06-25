class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length()) return false; 

        unordered_map<char,int> ump;

        for(auto&it:s)
            ump[it]++;
        for(auto&it:t){
            if(ump[it] == 0)
                return false;
            ump[it]--;
        }

        return true;
    }
};