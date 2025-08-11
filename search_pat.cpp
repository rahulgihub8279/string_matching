class Solution
{
public:
    void findlps(vector<int> &lps, string s)
    {
        int n = s.length();
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
    }
    vector<int> search(string &pat, string &txt)
    {
        int n = txt.length();
        int m = pat.length();
        vector<int> LPS(m, 0);
        vector<int> ans;
        findlps(LPS, pat);
        int i = 0, j = 0;

        while (i < n)
        {
            if (txt[i] == pat[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = LPS[j - 1];
            }
            if (j == m)
            {
                ans.push_back(i - j);
                j = LPS[j - 1];
            }
        }
        return ans;
    }
};