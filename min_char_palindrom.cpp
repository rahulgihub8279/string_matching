class Solution
{
public:
    void findlps(vector<int> &lps, string s)
    {
        int pref = 0, suff = 1;
        while (suff < s.length())
        {
            if (s[pref] == s[suff])
            {
                lps[suff] = pref + 1;
                suff++;
                pref++;
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

    int minChar(string &s)
    {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());

        s += '$';
        s += rev;
        int m = s.length();
        vector<int> lps(m, 0);
        findlps(lps, s);

        return n - lps[m - 1];
    }
};
