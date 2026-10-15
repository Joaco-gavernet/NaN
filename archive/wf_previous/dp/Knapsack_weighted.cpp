vector<bool> knapsack_weighted(vector <int> v, int n) {
	int sum = accumulate(all(v),0LL);
	vector <bool> dp(sum+1,false);
	dp[0] = true;
	sort(all(v));
	vector <pair<int,int>> num; // (number,#counter)
	int count = 1, last = v[0];
	forr(i,1,n) {
		if(v[i] == last) count++;
		else {
			num.pb({last,count});
			last = v[i];
			count = 1;
		}
	}
	num.pb({last,count});
	for(auto [x,c] : num) {
		vector <bool> next_dp = dp;
		forn(i,x) {
			int can = 0;
			for(int j = i; j <= sum; j += x) {
				next_dp[j] = next_dp[j] | (can>0);
				if(dp[j]) can++;
				if(j - c*x >= 0 and dp[j-c*x]) can--; 
			}
		}
		dp = next_dp;
	}
	return dp;
}
