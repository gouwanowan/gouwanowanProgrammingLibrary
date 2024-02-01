#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

char re(vector<vector<char> > &s, int h, int w, int x, int y){
    if (s.at(x).at(y) == '.')
    {
        return '.' ;
    }else
    {
        for (int i = max(x-1,0); i < min(h,x+2); i++)
        {
            for (int j = max(y-1,0); j < min(y+2,w); j++)
            {
                if (s.at(i).at(j) == '.')
                {
                    return '.' ;
                }
                
            }
            
        }
        return '#' ;
    }
    
    
}
