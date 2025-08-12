class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        vector<int> lps(n, 0);
        int pref = 0, suff = 1;
        while (suff < n)
        {
            if (s[pref] == s[suff])
            {
                lps[suff] = pref + 1;
                pref++;
                suff++;
            }
            else
            {
                if (pref == 0)
                {
                    lps[suff] = 0;
                    suff++;
                }
                else
                {
                    pref = lps[pref - 1];
                }
            }
        }
        int len = lps[n - 1];
        string ans = s.substr(0, len);
        return ans;
    }
};