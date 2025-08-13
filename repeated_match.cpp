class Solution
{
public:
    void find_lps(vector<int> &lps, string pat)
    {
        int pref = 0, suff = 1;
        while (suff < pat.length())
        {
            if (pat[suff] == pat[pref])
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
    bool KMP(string txt, string pat)
    {
        int n = txt.length(), m = pat.length();
        vector<int> lps(m, 0);
        find_lps(lps, pat);
        int l = 0, r = 0;
        while (l < n && r < m)
        {
            if (txt[l] == pat[r])
            {
                l++;
                r++;
            }
            else
            {
                if (r == 0)
                    l++;
                else
                    r = lps[r - 1];
            }
        }
        return r == m;
    }
    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 1;
        int repeat = 1;
        string temp = a;
        while (temp.length() < b.length())
        {
            temp += a;
            repeat++;
        }
        // KMP
        if (KMP(temp, b))
            return repeat;
        temp += a;
        if (KMP(temp, b))
            return repeat + 1;

        return -1;
    }
};