#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std ;

int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}} ;

/*
h*wのグリッドで最短経路を求める
h:盤面の縦幅
w:盤面の横幅
board:そのマスに侵入するためのコストを格納
s:スタート
g:ゴール
*/
int gridBFS(int h, int w, vector<vector<int>> &board,pair<int,int> s, pair<int,int> g){
    //確定した最短経路を格納する
    vector<vector<int>> cost(h,vector<int>(w,-1)) ;

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
            if (nx < 0 || h <= nx || ny < 0 || w <= ny)
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

int main() {
    //ARC005C:器物損壊！高橋君の場合
    int h,w ;
    cin >> h >> w ;
    vector<string> str(h) ;
    vector<vector<int>> map(h,vector<int>(w,0)) ;

    pair<int,int> s;
    pair<int,int> g;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            
            char c ;
            cin >> c ;
            if (c == 's')
            {
                s = make_pair(i,j) ;
            }else if (c == 'g')
            {
                g = make_pair(i,j) ;
            }else if (c == '#')
            {
                map.at(i).at(j) = 1 ;
            }
            
        }
        
    }
    
    if (gridBFS(h,w,map,s,g) <= 2)
    {
        cout << "YES" << endl ;
    }else
    {
        cout << "NO" << endl ;
    }
        
    return 0;
}