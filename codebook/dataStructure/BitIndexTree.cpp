//N -> BIT陣列大小bit.size()
int query(int x){
    int ret = 0;
    while(x){
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}

void update(int x, int d){
    while(x <= N){
        b[x] += d;
        x += x & (-x);
    }
}
