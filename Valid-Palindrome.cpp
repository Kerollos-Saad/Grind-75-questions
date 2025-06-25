class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto&it:s)
        {
            if(isalnum(it))
            {
                temp += tolower(it);
            }
        }

        int left = 0;
        int right = temp.size() - 1;

        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};