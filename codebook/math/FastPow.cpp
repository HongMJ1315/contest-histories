ll mypow(ll m, ll n, ll mod){
    ll ans=1;
    for (; n > 0; n >>= 1){
        if (n&1)
            ans = ans * m % mod;
        m = m * m % mod;
    }
}
