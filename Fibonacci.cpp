#include <iostream>
using namespace std;

int main(){    
    int64_t an,an_1,an_2 ;
    an_1 = 1 ;
    an_2 = 0 ;
    cout << "a0:"<< an_2 << endl ;
    cout << "a1:"<< an_1 << endl ;
    for (int i = 2; i < 61; i++)
    {
        an = an_1 + an_2 ;
        an_2 = an_1 ;
        an_1 = an ;
        cout << "a" << i << ":" << an << endl ;
    }
    
}