#include <iostream>
using namespace std;

// void func(int i, int sum)
// {
//     if(i<1) return;
//     func(i-1, sum +i);
//     cout<<sum <<endl;
        
// }


// void sumOfn(int i ,int sum){
//     if(i<1) return;
//     sumOfn(i-1, sum+i);
//     cout<< sum <<endl;
// }



int fact(int n){
    if(n<1) return 1;
    return n* fact(n-1);
}

int main()
{
    int n;
    cin>> n;
    cout<< fact(n);
    return 0;
}