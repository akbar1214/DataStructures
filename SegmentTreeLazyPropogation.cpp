// In the name of ALLAH

#include<bits/stdc++.h>

#define ll  long long
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define pb push_back
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
const int con = 100005;

ll tree[4*con];
ll lazy[4*con];

void build(int low,int high,int index){

    if(low > high) return;

    if(low == high){
        tree[index] = 0;
        return;
    }

    int mid = (low+high) / 2;
    build(low,mid,2*index);
    build(mid+1,high,2*index+1);
    tree[index] = tree[2*index] + tree[2*index+1];
}

void update(int low,int high,int qlow,int qhigh,int index,ll val){

    if(lazy[index] > 0){

        tree[index] += (high - low + 1) * lazy[index];

        if(low != high){

            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];

        }
        lazy[index] = 0;
    }

    if(low > high || low > qhigh || high < qlow) return;

    //complete overlap
    if(low >= qlow && high <= qhigh){

        tree[index] += (high-low+1)*val;
        if(low != high){
            lazy[2*index] += val;
            lazy[2*index+1] += val;
        }
        return;
    }

    int mid = (low + high) / 2;

    update(low,mid,qlow,qhigh,2*index,val);

    update(mid+1,high,qlow,qhigh,2*index+1,val);

    tree[index] = tree[2*index] + tree[2*index+1];
}

ll sum(ll low,ll high,ll qlow,ll qhigh,ll index){

    if(lazy[index]){

        tree[index] += (high-low+1)*lazy[index];

        if(high != low){

            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];

        }
        lazy[index] = 0;
    }
    if(low > qhigh || high < qlow) return 0;

    if(low >= qlow && high <= qhigh){

        return tree[index];
    }
    int mid = (high+low) / 2;
    return sum(low,mid,qlow,qhigh,2*index) + sum(mid+1,high,qlow,qhigh,2*index+1);
}

int main() {
    FASTIO

    int T;cin >> T;
    while(T--){

        ll n,q;cin >> n >> q;
        ll type,l,r,val;
        FOR(i,0,4*con){
            tree[i] = 0;
            lazy[i] = 0;
        }
        while(q--){
            cin >> type >> l >> r;
            if(type == 0){
                cin >> val;
                update(1,n,l,r,1,val);
            }else{
                cout << sum(1,n,l,r,1) << endl;
            }
        }
    }

    return 0;
}
