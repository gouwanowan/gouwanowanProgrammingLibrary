#include <iostream>
#include <vector>

//二次元リストを右に90度回転
//TODO:長方形でも対応できているか確認する
vector<vector<char>> rightRot90(vector<vector<char>> oldgrid){
    vector<vector<char>> newgrid(oldgrid.at(0).size(),vector<char>(oldgrid.size(),'.')) ;
    for (int i = 0; i < oldgrid.size(); i++)
    {
        for (int j = 0; j < oldgrid.at(i).size(); j++)
        {
            newgrid.at(j).at(oldgrid.at(i).size()-1-i) = oldgrid.at(i).at(j) ;
        }
        
    }
    
    return newgrid ;
}
