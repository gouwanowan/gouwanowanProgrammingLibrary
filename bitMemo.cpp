#include <iostream>

// 参考文献
// https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361

// i番目のビットが1か
// if (bit & (1<<i))

// i番目のビットを立てる
// bit |= (1<<i)

// i番目のビットを消す
// bit &= ~(1<<i)

int main(){
    int n ;
    cin >> n ;
    for (int bit = 0; bit < pow(2,n); bit++)
    {
        for (int i = 0; i < n; i++)
        {
            if (bit & (1<<i))
            {
                //do something
            }
            
        }
        
    }
    
}