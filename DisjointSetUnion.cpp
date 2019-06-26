
//Here you can directly find the rank just by taking the absolute value
class DisjointSet {
 public:
    vector<int> parent;
    explicit DisjointSet(int n) {
        parent.resize(n, -1);
    }

    int find(int a) {

        if (parent[a] < 0) {
            return a;
        }
        return parent[a] = find(a);
    }

    void join(int a, int b) { //join b to a

        int pr = find(b);
        int pr1 = find(a);
        parent[pr1] += parent[pr];
        parent[pr] = pr1;
    }

};
