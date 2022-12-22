#include <bits/stdc++.h>
using namespace std ;

vector<int> merge(vector<int> leftPart, vector<int> rightPart) {
    vector<int> ans ;
    int i = 0 ;
    int j = 0 ;
    while(i < leftPart.size() && j < rightPart.size()) {
        if ( leftPart[i] <= rightPart[j]) {
            ans.push_back(leftPart[i]);
            i++ ;
        }
        else {
            ans.push_back(rightPart[j]);
            j++ ;
        }
    }
    if ( i == leftPart.size()) for ( int k = j ; k < rightPart.size() ; k++ ) ans.push_back(rightPart[k]);
    if ( j == rightPart.size()) for ( int k = i ; k < leftPart.size() ; k++ ) ans.push_back(leftPart[k]);
    return ans;
}

vector<int> mergeSort(vector<int>& v, int left, int right) {
    int mid = (left+right)/2 ;
    vector<int>leftPart,rightPart ;
    
    if ( left < mid ) leftPart = mergeSort(v,left,mid);
    if ( left == mid ) leftPart.push_back(v[left]);
    if ( mid+1 < right) rightPart = mergeSort(v,mid+1,right);
    if ( mid+1 == right ) rightPart.push_back(v[mid+1]);
    
    return merge(leftPart,rightPart); 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // for reading input and writing output
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    vector<int> v ;
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i++) {
        int a ;
        cin >> a ;
        v.push_back(a);
    }
    cout << "BEFORE SORTING" << endl;
    for ( int i = 0 ; i < v.size() ; i++ ) cout << v[i] << " " ;
    cout << endl;
    cout << "AFTER SORTING" << endl;
    vector<int> sortedV = mergeSort(v,0,n-1);
    for ( int i = 0 ; i < sortedV.size() ; i++ ) cout << sortedV[i] << " " ;
    cout << endl;
}