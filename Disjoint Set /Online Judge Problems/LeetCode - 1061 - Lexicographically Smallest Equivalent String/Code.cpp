#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    class DisjointSet{
    vector <int> parent ;
    public :
        DisjointSet(int n) {
            parent.resize(n+2);
            for ( int i = 0 ; i <= n ; i++) parent[i] = i ;
        }
        int findUltimateParent(int node) {
            if ( parent[node] == node) return node ;
            return parent[node] = findUltimateParent(parent[node]);
        }
        void unionSets(int node1, int node2) {
            int ult_parent_node1 = findUltimateParent(node1);
            int ult_parent_node2 = findUltimateParent(node2);
            if( ult_parent_node1 == ult_parent_node2 ) return ;
            if ( ult_parent_node1 < ult_parent_node2) parent[ult_parent_node2] = ult_parent_node1;
            else parent[ult_parent_node1] = ult_parent_node2;
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet disjointSet(26);
        string ans = "" ;
        for ( int i = 0 ; i < s1.size() ; i++) disjointSet.unionSets((int)(s1[i]-'a'),(int)(s2[i]-'a'));
        for ( int i = 0 ; i < baseStr.size() ; i++) ans += (char)(disjointSet.findUltimateParent((int)(baseStr[i]-'a')) + 'a');
        return ans ;
    }
};