#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

//座標圧縮
//vecの値を直接書き換える
void compress(vector<int64_t> &vec){
    vector<int64_t> vec_copy = vec ;
    sort(vec_copy.begin(), vec_copy.end());
    vec_copy.erase(unique(vec_copy.begin(), vec_copy.end()), vec_copy.end());

    for (int i = 0; i < vec.size(); ++i) {
        vec.at(i) = lower_bound(vec_copy.begin(), vec_copy.end(), vec.at(i)) - vec_copy.begin();
    }
    return ;
}
