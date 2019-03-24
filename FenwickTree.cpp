#include <iostream>
#include <vector>


using namespace std;

class FenwickTree{

    vector<int> v;
    int size;
public:
    FenwickTree(int n){
        v.resize(n+2);
        size = n;
    }

    void update(int index,int value){
        index++;
        while(index <= size){
            v[index] += value;
            index += (index & -index);
        }
    }

    long long sum(int index){
        index++;
        long long sum=0;
        while(index){
            sum += v[index];
            index -= index&-index;
        }
        return sum;
    }

    void print(){

        for(int i=1;i<=size;i++) cout << v[i] << " ";
    }
};


int main(){

    FenwickTree ft(10);
    for(int i=0;i<10;i++) ft.update(i,i+1);
    ft.print();
    cout << "\n\n";
    cout << ft.sum(10);
    return 0;
}
