class Solution
{
public:
    int getLPSLength(string &s)
    {
        int n = s.length();
        vector<int> LPS(n, 0);
        int pref = 0;
        int suff = 1;
        while (suff < n)
        {
            // MATCH
            if (s[pref] == s[suff])
            {
                LPS[suff] = pref + 1;
                pref++;
                suff++;
            }
            // NOT MATCH
            else
            {
                if (pref == 0)
                {
                    LPS[suff] = 0;
                    suff++;
                }
                else
                {
                    pref = LPS[pref - 1];
                }
            }
        }
        return LPS[n - 1];
    }
};