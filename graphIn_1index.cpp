#include <iostream>
#include <vector>


//1から頂点番号が始まるグラフを入力する
void GraphIn1index(vector<vector<int> > &list, int m){
        int a,b ;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b ;
        list.at(a-1).push_back(b-1) ;
        list.at(b-1).push_back(a-1) ;
    }
}

int main(){
    int n,m ;
    cin >> n >> m ;
    vector<vector<int> > list(n,vector<int> >(0)) ;
    GraphIn1index(list,m) ;
}
