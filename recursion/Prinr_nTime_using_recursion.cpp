#include<bits/stdc++.h>
using namespace std;
 
// void namePrint(string name, int n){
//     if (n<0) return;//base case
//     cout<< name<< endl;
//     namePrint(name,n-1); //recusive call
    
// }

// void func(int i ,int n)
// {
//     if(i<1) return;
//     cout<<i<< endl;

//     func(i-1,n);
// }


// int main()
// {   
//   int n=4;
//   func(n,n);
//   return 0;
   
// }




// void func(int i, int n){
//     if (i<1) return;
//     cout<< i<< endl;
//     func(i-1,n);
// }

int fonc(int i, int n){
    if(i<1) return ;
    fonc(i-1, n);
    cout<<i<< endl;
}

int main(){
    int n;
    cin>> n;
    fonc(n,n);
    return 0;
}