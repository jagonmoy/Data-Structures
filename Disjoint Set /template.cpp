#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent,size,rank ;
    public : 
    DisjointSet(int n) {
        parent.resize(n+2);
        size.resize(n+2,1);
        rank.resize(n+2,0);
        for ( int i = 0 ; i <= n ; i++) parent[i] = i ;
    }
    int findUltimateParent(int n) {
        if ( n == parent[n]) return n ;
        return parent[n] = findUltimateParent(parent[n]);
    }
    void unionBySize(int a, int b) {
        int ult_parent_a = findUltimateParent(a);
        int ult_parent_b = findUltimateParent(b);
        if ( ult_parent_a == ult_parent_b ) return ;
        if ( size[ult_parent_a] < size[ult_parent_b] ) {
            parent[ult_parent_a] = ult_parent_b;
            size[ult_parent_b] += size[ult_parent_a];
        }
        else {
            parent[ult_parent_b] = ult_parent_a;
            size[ult_parent_a] += ult_parent_b;
        }

    }
    void unionByRank(int a, int b) {
        int ult_parent_a = findUltimateParent(a);
        int ult_parent_b = findUltimateParent(b);
        if ( ult_parent_a == ult_parent_b ) return ;
        if ( rank[ult_parent_a] < rank[ult_parent_b] ) parent[ult_parent_a] = ult_parent_b;
        else if ( rank[ult_parent_b] < rank[ult_parent_a] ) parent[ult_parent_b] = ult_parent_a;
        else {
            parent[ult_parent_b] = ult_parent_a ;
            rank[ult_parent_a]++ ;
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int numberOfNodes ;
    cin >> numberOfNodes ;
    DisjointSet disjointSet(numberOfNodes);

    while(1) {
        string str ;
        cin >> str ;
        if (str == "Edge") {
            int a,b ;
            cin >> a >> b ;
            disjointSet.unionBySize(a,b);
        }
        else if ( str == "Query") {
            int a,b ;
            cin >> a >> b ;
            if ( disjointSet.findUltimateParent(a) != disjointSet.findUltimateParent(b)) cout << "Not in same component" << endl;
            else cout << "In same component" << endl;
        }
        else if (str == "End") break ;
    }


    return 0;
}

