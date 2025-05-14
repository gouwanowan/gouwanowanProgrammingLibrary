#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

/*
STLの二分探索の使い方に関する覚書(執筆中)

参考文献
https://qiita.com/ganyariya/items/33f1326154b85db465c3
*/

//bool binary_search(a.begin(),a.end(),key)
//配列aの中にkeyがあるかどうかを返す

int main(){
    vector<int> a ;
    int key ;
    //昇順にソートしておく
    sort(a.begin(),a.end()) ;

    //key未満の要素の数
    lower_bound(a.begin(), a.end(), key) - a.begin() ;
    //key以下の要素の数
    upper_bound(a.begin(), a.end(), key) - a.begin() ;
}