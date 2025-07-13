class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = ""; s += num[0];
        for(int i=1;i<num.length();++i) {
            // if removal attempts are left (k>0)
            // and nums[i] is less than last element of s
            // then remove last element of s and come back to nums[i] again
            if(k > 0 && s.length() > 0 && num[i] < s[s.length()-1]) {
                s.pop_back();
                k--;
                i--;
                continue;
            }
            else
            s += num[i];
        }
        // if removal attempts are left remove characters at the end
        // because at this point s contains characters in ascending order
        // so preferable to remove larger characters at the end
        while(k > 0 && s.length() > 0) {
            s.pop_back();
            k--;
        }

        while(s[0] == '0') {      // remove trailing zeroes if any
            s.erase(s.begin());
        }
        
        if(s.length() == 0) s = "0";   // if final s is empty then indicates 0
        return s;
    }
};