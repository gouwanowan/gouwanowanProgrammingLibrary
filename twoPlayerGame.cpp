#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdint>
#include <cmath>

using namespace std ;

/*
これはテンプレートなので細かい部分は毎回自分で書いてね
*/

/*
dp:各状態での勝ち負けを記録
state:現在の状態
first:先手側の手番かどうか
*/
bool ifWinFirst(vector<int> &dp, int state, bool first){
    //一度調べた状態ならすぐに返す
    if (dp.at(state) != -1)
    {
        if (dp.at(state))
        {
            return true ;
        }else
        {
            return false ;
        }
        
    }

    //可能な遷移を列挙する
    vector<int> ablemove(0) ;

    for (int i = 0; i < ablemove.size(); i++)
    {
        int newstate = ablemove.at(i) ;
        //手番のプレイヤーが勝てる遷移がひとつでもあれば手番側の勝ち
        if (first)
        {
            if (ifWinFirst(dp,newstate,!first) == true)
            {
                dp.at(state) = 1 ;
                return true;
            }
        }else
        {
            if (ifWinFirst(dp,newstate,!first) == false)
            {
                dp.at(state) = 0 ;
                return false;
            }
        }
        
    }
    //すべての遷移先で負けなら手番側の負け
    if (first)
    {
        dp.at(state) = 0 ;
        return false;
    }else
    {
        dp.at(state) = 1 ;
        return true;
    }
    
    
}

int main() {	
    int n ;
    cin >> n ;
    vector<int> dp(100,-1) ;
    int initialstate = 0 ;
    if (ifWinFirst(dp,initialstate,1))
    {
        cout << "Takahashi" << endl ;
    }else
    {
        cout << "Aoki" << endl ;
    }
}