#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <queue>

using namespace std;

vector<vector<pair<int64_t,int64_t>>> WeightedGraphInput(int Nodes, int Edges, bool Undirected, bool OneIndexed){
    vector<vector<pair<int64_t,int64_t>>> list(Nodes, vector<pair<int64_t,int64_t>>(0)) ;
    int StartIndex = 0 ;
    if (OneIndexed)
    {
        StartIndex = 1 ;
    }
    for (int i = 0; i < Edges; i++)
    {
        int64_t a,b,c ;
        cin >> a >> b >> c ;
        list.at(a-StartIndex).push_back(make_pair(b-StartIndex,c)) ;
        if (Undirected)
        {
            list.at(b-StartIndex).push_back(make_pair(a-StartIndex,c)) ;
        }
    }
    return list ;
}

vector<int64_t> Dijkstra(vector<vector<pair<int64_t,int64_t>>> graph, int start){
    int64_t INF = INT64_MAX ;
    vector<int64_t> dist(graph.size(),INF) ;
    priority_queue<pair<int64_t,int64_t>> wait ;
    wait.push(make_pair(0,start)) ;
    while (!wait.empty())
    {
        int64_t v = wait.top().second ;
        int64_t c = wait.top().first * -1 ;
        wait.pop() ;
        if (dist.at(v) != INF)
        {
            continue;
        }
        dist.at(v) = c ;
        for (int i = 0; i < graph.at(v).size(); i++)
        {
            wait.push(make_pair(((c + graph.at(v).at(i).second)*-1),graph.at(v).at(i).first)) ;
        }
        
    }
    return dist ;
}

int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<pair<int64_t,int64_t>>> graph = WeightedGraphInput(n,m,false,false) ;
    vector<int64_t> ans = Dijkstra(graph,r) ;
    
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.at(i) == INT64_MAX)
        {
            cout << "INF" << endl ;
        }else
        {
            cout << ans.at(i) << endl ;
        }
        
    }
    
}