//BIT at here
int main(){
    vector<int> arr, idx, res;
    bit.resize(arr.size() + 10);
    res.resize(idx.size());
    idx.resize(unique(idx.begin(), idx.end()) - idx.begin());
    sort(idx.begin(), idx.end());
    for(int i = 0; i < res.size(); i++)
        res[i] = lower_bound(idx.begin(), idx.end(), all[i]) - idx.begin() + 1;
    int ans = 0;
    for(int i = all.size() - 2; i >= 0; i -= 2){
        ans += query(res[i] - 1);
        update(res[i], 1);
    }
    cout << ans << endl;
}
