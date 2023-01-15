#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    unordered_map <int,int> hashmap,parent,size ;
    int findParent(int node) {
        if (parent[node] == node) return node ;
        return parent[node] = findParent(parent[node]);
    }
    void makeUnion(int a, int b) {
        int ult_par_a = findParent(a);
        int ult_par_b = findParent(b);
        if ( ult_par_a == ult_par_b ) return ;
        if ( ult_par_a  <  ult_par_b ) {
            parent[ult_par_b] = ult_par_a;
            size[ult_par_a] += size[ult_par_b] ;
        }    
        else {
            parent[ult_par_a] = ult_par_b;
            size[ult_par_b] += size[ult_par_a] ;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for ( int i = 0 ; i < n ; i++) parent[nums[i]] = nums[i] ;
        for ( int i = 0 ; i < n ; i++) size[nums[i]] = 1 ;
        for ( int i = 0 ; i < n ; i++) hashmap[nums[i]] = 1 ;
        for ( int i = 0 ; i < n ; i++) {
            if ( hashmap[nums[i]-1] ) makeUnion(nums[i]-1,nums[i]);
            if ( hashmap[nums[i]+1] ) makeUnion(nums[i],nums[i]+1);
        }
        int ans = 0 ;
        for ( int i = 0 ; i < n ; i++ ) ans = max(ans,size[nums[i]]);
        return ans;
    }
};