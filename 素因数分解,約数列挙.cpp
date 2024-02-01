#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int64_t,int64_t> > bunkai(int64_t n){
    vector<pair<int64_t,int64_t> > prime(0,pair<int64_t,int64_t>()) ;
    for (int64_t j = 2; j < sqrt(n)+1; j++)
    {
        while(1){            
            if (n % j == 0)
            {
                prime.push_back(make_pair(j,1)) ;
                n /= j ;
                while (n % j == 0)
                {
                    prime.at(prime.size()-1).second ++ ;
                    n /= j ;
                }
                
            }else
            {
                break ;
            }
            
            if (n == 1)
            {
                break ;
            }
            
        }
        
    }
    if (n > 1)
    {
        prime.push_back(make_pair(n,1)) ;
    }
    return prime ;
}

vector<int64_t> divlist(vector<pair<int64_t,int64_t> > &prime){
    vector<int64_t> list(0) ;
    vector<int> nowindex(prime.size(),0) ;
    bool endf = 0 ;
    while (!endf)
    {
        int64_t push = 1 ;
        for (int i = 0; i < prime.size(); i++)
        {
            
            push *= pow(prime.at(i).first,nowindex.at(i))/ 1 ;
        }
        list.push_back(push) ;
        bool ok = 0 ;
        int c = 0 ;
        while (1)
        {
            if (c >= prime.size())
            {
                endf = 1 ;
                break ;
            }
            
            if (nowindex.at(c) == prime.at(c).second)
            {
                nowindex.at(c) = 0 ;
                c ++ ;
            }else
            {
                nowindex.at(c) ++ ;
                break ;
            }
            
            
        }
        
        
    }
    return list ;
}

int main(){
    int n ;
    cin >> n ;
    vector<pair<int64_t,int64_t> > prime;
    prime = bunkai(n) ;
    for (int i = 0; i < prime.size(); i++)
    {
        cout << prime.at(i).first << '^' << prime.at(i).second << endl ;
    }
    
}