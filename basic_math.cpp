// Digit count

#include<bits/stdc++.h>
using namespace std;

// int count(int n)
// {
//     int cnt=0;
//    for(;n>0; n= n/10){
//     cnt++;
//    }
//    return cnt;
   
// }

// // using Log

// int count(int n)
// {
//     int cnt = (int) (log10(n)+1);
//     return cnt;
// }

// reaverse number

int reverseNumber(int n){
  int rvrs =0;
  while (n>0)
  {
    /* code */
    int ld= n%10;
    rvrs = (rvrs * 10)+ld;
    n=n/10;
  }
  return rvrs;
}


// Palindrome Number
int main(){
    int n;
    cin >>n;
    int original=n;
    int num = 0;
   
     while (n>0)
    {
        int ld = n%10;
        num= (num*10)+ld;
        n=n/10;
    }
    cout<<num;

    if (original==num){
        cout<<"true";
    }
     else{
       cout<<"false";
     }
    }




// int main()
// {
//   int n;
//   cin>>n;
//   cout<<reverseNumber(n);

//   if ()


// }

