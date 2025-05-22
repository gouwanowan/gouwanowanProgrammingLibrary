#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <atcoder/all>

using namespace std;


void compress(vector<int64_t> &vec){
    vector<int64_t> vec_copy = vec ;
    sort(vec_copy.begin(), vec_copy.end());
    vec_copy.erase(unique(vec_copy.begin(), vec_copy.end()), vec_copy.end());

    for (int i = 0; i < vec.size(); ++i) {
        vec.at(i) = lower_bound(vec_copy.begin(), vec_copy.end(), vec.at(i)) - vec_copy.begin();
    }
    return ;
}

//配列aの転倒数を求める関数
//aの座標圧縮が必須
//fenwick_treeはACLを使用する
int64_t inv_num(vector<int64_t> a){
    atcoder::fenwick_tree<int64_t> fw(a.size()+1) ;
    int64_t ret = 0 ;
    for (int i = 0; i < a.size(); i++)
    {
        int ai = a.at(i) ;
        fw.add(ai,1) ;
        ret += fw.sum(ai+1,a.size()+1) ;
    }
    return ret ;
}
