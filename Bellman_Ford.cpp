#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std ;

vector<int64_t> BellmanFord(vector<vector<pair<int64_t,int64_t>>>graph, int start){
    int64_t INF = INT64_MAX ;
    vector<int64_t> dist(graph.size(), INF) ;
    dist.at(start) = 0 ;
    for (int iter = 0; iter < graph.size(); iter++)
    {
        bool update = false ;
        for (int v = 0; v < graph.size(); v++)
        {
            if (dist.at(v) == INF)
            {
                continue;
            }
            for (int e = 0; e < graph.at(v).size(); e++)
            {
                if (dist.at(graph.at(v).at(e).first) > dist.at(v) + graph.at(v).at(e).second)
                {
                    update = true ;
                    dist.at(graph.at(v).at(e).first) = dist.at(v) + graph.at(v).at(e).second ;
                }
                
            }
            
        }
        if (!update)
        {
            break ;
        }
        if (update && (iter == graph.size()-1))
        {
            return {-1} ;
        }
        
    }
    return dist ;
}

vector<vector<pair<int64_t,int64_t>>> graphInput(int Nodes, int Edges, bool Undirected, bool OneIndexed){
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

int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<pair<int64_t,int64_t>>> graph = graphInput(n,m,false,false) ;
    vector<int64_t> ans = BellmanFord(graph,r) ;
    if (ans.size() == 1 && ans.at(0) == -1)
    {
        cout << "NEGATIVE CYCLE" << endl ;
    }else
    {
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
    
}