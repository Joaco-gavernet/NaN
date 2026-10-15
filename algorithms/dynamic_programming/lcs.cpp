// Longest Common Subsequence
// O(n*m) time, O(n*m) space
// Usage: LCS(s1,s2)

string LCS(string s1, string s2) { // O(n*m)
    const int n = SZ(s1), SZ(s2);
    int dp[n+1][m+1]; pair<int,int> last[n+1][m+1];
    forn(i,n+1) {
        forn(j,m+1) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1]+1, last[i][j] = {i-1,j-1}; 
            else if(dp[i-1][j] > dp[i][j-1]) 
                dp[i][j] = dp[i-1][j], last[i][j] = {i-1,j}; 
            else dp[i][j] = dp[i][j-1], last[i][j] = {i,j-1};
        }
    }
    string ans; pair<int,int> cur = {n,m};
    while(cur.first != 0 && cur.second != 0) {
        int x = cur.first, y = cur.second;
        if(x-last[x][y].first==1 && y-last[x][y].second==1) ans += s1[x-1];
        cur = last[x][y]; 
    }
    reverse(all(ans));
    return ans;
}
