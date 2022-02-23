struct node{
    int data;
    node *lch,*rch;
    node(int data):data(data),lch(nullptr),rch(nullptr){}
    void pull(){
        data=0;
        if(lch!=nullptr) data+=lch->data;
        if(rch!=nullptr) data+=rch->data;
    }
};
void modify(int l,int r,int pos,node *pre,node *now,int data){
    if(l==r)
        now->data=data;
    else{
        now->lch=pre->lch;
        now->rch=pre->rch;
        int mid=(l+r)>>1;
        if(pos<=mid){
            now->lch=new node(0);
            modify(l,mid,pos,pre->lch,now->rch,data);
        }
        else{
            now->lch=new node(0);
            modify(mid+1,r,pos,pre->rch,now->rch,data);
        }
        now->pull();
    }
}
int find(int l,int r,node *p,int k){
    if(l==r) return l;
    int mid=(l+r)>>1;
    int l_size = p->lch->data;
    if(k<=l_size)
        return find(l,mid,p->lch,k);
    else 
        return find(mid+1,r,p->rch,k-l_size); 
}
void build(int l,int r,node *p){
    if(l==r) return;
    int mid=(l+r)>>1;
    p->lch=new node(0);
    build(l,mid,p->lch);
    p->rch=new node(0);
    build(mid+1,r,p->rch);
}
const int maxn=1000005;
int arr[maxn];
node *T[maxn];
int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> dct;
    for(int i=0;i<=N;i++)
        cin>>arr[i],dct.push_back(arr[i]);
    sort(dct.begin(),dct.end());
    dct.resize(unique(dct.begin(),dct.end(),arr[i])-dct.begin());
    T[0]=build(0,(int)dct.size()-1);
    for(int i=1;i<=N;i++){
        arr[i]=lower_bound(dct.begin(),dct.end(),arr[i])-dct.begin();
        T[i]=new node(0);
        modify(0,(int)dct.size()-1,T[i-1],T[i],arr[i]);
    }
    while(Q--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<dct[find(0,(int)dct.size()-1,T[l-1],T[r],k)]<<endl;
    }
}