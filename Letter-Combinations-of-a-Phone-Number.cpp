class Solution {
public:

    void backTrack(string curr,string digits, unordered_map<char, vector<char>> ump, 
    vector<string>& res,int pos=0){

        if(pos == digits.size()){
            res.push_back(curr);
            return;
        }

        for(auto& c : ump[digits[pos]]){
            curr = curr + c;
            backTrack(curr,digits, ump, res, pos+1);
            curr.erase(curr.length() - 1,1);
        }

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> ump;
        vector<string> res;
        if (digits.length() == 0) return res;


        ump['2'] = vector<char>{'a','b','c'};
        ump['3'] = vector<char>{'d','e','f'};
        ump['4'] = vector<char>{'g','h','i'};
        ump['5'] = vector<char>{'j','k','l'};
        ump['6'] = vector<char>{'m','n','o'};
        ump['7'] = vector<char>{'p','q','r','s'};
        ump['8'] = vector<char>{'t','u','v'};
        ump['9'] = vector<char>{'w','x','y','z'};

        backTrack("",digits,ump,res);
        return res;


    }
};