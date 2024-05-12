#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std ;

int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}} ;

/*
n*nのグリッドで最短経路を求める
n:盤面の大きさ
board:そのマスに侵入するためのコストを格納
s:スタート
g:ゴール
*/
int gridBFS(int n, vector<vector<bool>> board,pair<int,int> s, pair<int,int> g){
    //確定した最短経路を格納する
    vector<vector<int>> cost(n,vector<int>(n,-1)) ;

    cost.at(s.first).at(s.second) = 0 ;

    priority_queue<pair<int,pair<int,int>>> wait ;
    wait.push(make_pair(0,s)) ;

    while (!wait.empty())
    {
        int x = wait.top().second.first ;
        int y = wait.top().second.second ;
        int c = cost.at(x).at(y) ;
        wait.pop() ;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + d[i][0] ;
            int ny = y + d[i][1] ;
            if (nx < 0 || n <= nx || ny < 0 || n <= ny)
            {
                continue;
            }
            if (cost.at(nx).at(ny) != -1)
            {
                continue;
            }
            int nc = cost.at(x).at(y) + board.at(nx).at(ny) ;
            cost.at(nx).at(ny) = nc ;
            //コストが小さい順に見るので-1倍してキューへ
            wait.push(make_pair(-nc,make_pair(nx,ny))) ;
        }
        

    }
    
    return cost.at(g.first).at(g.second) ;
}
