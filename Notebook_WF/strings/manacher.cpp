vi d1;      //d1[i] = max odd palindrome centered on i
vi d2;      //d2[i] = max even palindrome centered on i
            //s  aabbaacaabbaa
            //d1 1111117111111
            //d2 0103010010301
void manacher(string& s){
    ll l=0,r=-1,n=SZ(s);
    d1.resize(n), d2.resize(n);
    forn(i, n){
        ll k = (i>r ? 1 : min(d1[l+r-i],r-i));
        while(i+k<n && i-k>=0 && s[i+k]==s[i-k]) k++;
        d1[i] = k--;
        if(i+k>r) l=i-k,r=i+k;
    }
    l=0; r=-1;
    forn(i, n){
        ll k = (i>r ? 0 : min(d2[l+r-i+1],r-i+1)); k++;
        while(i+k<=n && i-k>=0 && s[i+k-1]==s[i-k]) k++;
        d2[i] = --k;
        if(i+k-1>r) l=i-k, r=i+k-1;
    }
}