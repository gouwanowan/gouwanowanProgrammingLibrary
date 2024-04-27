#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

//一次元リストについて|a[i]-a[j]|の和を求める
int64_t distSum(vector<int64_t> v){
    int64_t distsum = 0 ;
    sort(v.begin(),v.end()) ;
    int64_t s = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        int64_t nowp = v.at(i) ;
        distsum += nowp*(2*i + 1 - s) ;
    }
    return distsum ;
}

int main(){
    int n ;
    cin >> n ;
    vector<int64_t> v(n) ;
    for ( int i = 0; i < n; i++)
    {
        cin >> v.at(i) ;
    }

    cout << distSum(v) << endl ;

    return 0 ;
}