class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ump;

        for(auto&it:magazine)
            ump[it]++;
        
        for(auto&it : ransomNote){
            if(ump[it] == 0) return false;
            ump[it]--;
        }

        return true;
    }
};