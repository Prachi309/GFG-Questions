class Solution {
  public:
    bool wildCard(string &s, string &p) {
        // code here
        int m = s.size();
       int n = p.size();
    
    vector<bool> prev(m + 1, false);
    vector<bool> curr(m + 1, false);
    
    prev[0] = true;

    for (int i = 1; i <= n; i++) {
       
        bool flag = true;
        for (int ii = 1; ii <= i; ii++) {
            if (p[ii - 1] != '*') {
                flag = false;
                break;
            }
        }
        curr[0] = flag;

        for (int j = 1; j <= m; j++) {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                curr[j] = prev[j - 1];
            } else if (p[i - 1] == '*') {
                curr[j] = prev[j] || curr[j - 1];
            } else {
                curr[j] = false;
            }
        }

        
        prev = curr;
    }

    return prev[m];
    }
};