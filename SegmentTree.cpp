#include<bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=a;i<b;i++)

 
using namespace std;

int input[100003],tree[1<<18];

void constructTree(int low,int high,int index){

    if(low == high){
        tree[index] = input[low];
        return;
    }

    int mid = (low+high) >> 1;
    constructTree(low,mid,2*index);
    constructTree(mid+1,high,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
}

void update(int left,int right,int idx,int index,int val){

    if(left == right){
        tree[index] = val;
        return;
    }
    int mid = (left+right)/2;
    if(idx >= left && idx <= mid)
        update(left,mid,idx,2*index,val);
    else 
        update(mid+1,right,idx,2*index+1,val);

    tree[index] = min(tree[2*index],tree[2*index+1]);
}


int rangeMinimumQuery(int qlow,int qhigh,int low,int high,int index){

    //no overlap
    if(qlow > high || qhigh < low){
        return INT_MAX;
    }
    if(low >= qlow && high <= qhigh){
        return tree[index];
    }
    int mid = (low+high) >> 1;
    return min(rangeMinimumQuery(qlow,qhigh,low,mid,2*index),rangeMinimumQuery(qlow,qhigh,mid+1,high,2*index+1));
}



int main() {
     
    int n,q;cin >> n >> q;
    FOR(i,0,n){
        cin >> input[i];
    }
    constructTree(0,n-1,1);
    char st;
    int l,r;
    while(q--){

        cin >> st;
        if(st == 'q'){
            cin >> l >> r;
            if(l > r) swap(l,r);
            cout << rangeMinimumQuery(l-1,r-1,0,n-1,1) << endl;
        }else{
            cin >> l >> r;
            update(0,n-1,l-1,1,r);
        }
    }
}
