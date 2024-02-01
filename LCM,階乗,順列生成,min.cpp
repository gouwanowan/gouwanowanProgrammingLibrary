#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;
ostringstream oss ;

//最小公倍数（正しい略称はLCM）
int64_t lcm(int64_t a,int64_t b){
    if(a < b)
    {
        int64_t temp = a;
        a = b ;
        b = temp;
    }
    int64_t copya = a;
    int64_t copyb = b;
    int64_t r = a%b ;
    while (r != 0)
    {
        a = b ;
        b = r ;
        r = a%b ;
    }
    return copya * copyb / b ;
    
}
//階乗
int64_t bikkuri(int n){
    int ans = 1 ;
    for (size_t i = 1; i < n+1; i++)
    {
        ans *= i ;
    }
    return ans ;
}

//順列生成
vector<vector<int> >perm(0,vector<int>()) ;

void junretsu(vector<int> now, vector<int> rest, int len){
    if (now.size() == len)
    {
        perm.push_back(now) ;
    }else
    {
        
        for (int i = 0; i < rest.size(); i++)
        {
            int copy = *rest.begin() ;
            now.push_back(copy) ;
            rest.erase(rest.begin()) ;
            p(now,rest,len) ;
            rest.push_back(copy) ;
            now.pop_back() ;
        }
        
    }
    
    
}


//最小値（2数）
int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


int main(){
}