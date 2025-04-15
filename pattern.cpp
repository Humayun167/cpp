
// #include <iostream>
// using namespace std;

// void printstar(){
//     for ( int i= 0; i<=5; i++)
//     {
//         // cout << "*";
//         for(int j = 0; j<=i;j++)
//         {
//             cout << "*";
//         }
//         cout<< endl;
//     }
// }

// int main()
// {
// printstar();
// }

// #include<iostream>
// using namespace std;

// void printNumber()
// {
//     for(int i =1; i<=5;i++){
//         for(int j =1;j<=i; j++){
//             cout <<j<<" ";
//         }
//         cout<< endl;
//     }
// }

// int main()
// {
// printNumber();
// }

// #include <iostream>
// using namespace std;

// void revarseStar(){
//   for(int i=1; i<=5;i++){
//     for(int j=0; j<5-i+1; j++){
//         cout << "* ";
//     }
//     cout << endl;
//   }
// }

// int main()
// {

//         revarseStar();

// }
// #include <iostream>
// using namespace std;

// void revarseNum(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i + 1; j++)
//         {
//             cout <<j<<"  ";
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//   int n;
//   cin>>n;
//     revarseNum(n);
// }
#include <iostream>
using namespace std;

// void print7(int n)
// {
//   for (int i = 0; i < n; i++)
//   {
//     // space
//     for (int j = 0; j < n - i - 1; j++)
//     {
//       cout << " ";
//     }
//     // star
//     for (int j = 0; j < 2 * i + 1; j++)
//     {
//       cout << "* ";
//     }
//     // space
//     for (int j = 0; j < n - i - 1; j++)
//     {
//       cout << " ";
//     }
//     cout << endl;
//   }
// }
void print8(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    // star
    for (int j = 0; j < 2 * n - (2 * i + 1); j++)
    {
      cout << "* ";
    }
    // space
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    cout << endl;
  }
}

// int main()
// {
//   int n;
//   cin>>n;
//     print7(n);
//     print8(n);
// }

void print9(int n)
{
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    int stars = i;
    if (i > n)
      stars = 2 * n - i;
    for (int j = 1; j <= stars; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void print10(int n)
{
  for (int i = 1; i < 2 * n - 1; i++)
  {
    int star = i;
    if (i > n)
      star = 2 * n - i;

    for (int j = 1; j <= star; j++)
    {
      cout << "8";
    }
    cout << endl;
  }
}

// void print11(int n)
// {
//   int start = 1;
//   for (int i = 0; i < n; i++)
//   {
//     if (i % 2 == 0)
//       start = 1;
//     else
//       start = 0;
//     for (int j = 0; j <= i; j++)
//     {
//       cout << start;
//       start = 1 - start;
//     }
//     cout << endl
//   }
// }

void print12(int n)

{
  int space = 2 * (n - 1);
  for (int i = 1; i <= n; i++)
  {
    // number
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }
    // space
    for (int j = 1; j <= space; j++)
    {

      cout << " ";
    }
    // number
    for (int j = i; j >= 1; j--)
    {
      cout << j;
    }

    cout << endl;
    space -= 2;
  }
}

void print13(int n)
{
  int num = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << num << " ";
      num = num + 1;
    }
    cout << endl;
  }
}

void print14(int n)
{
  for (int i = 0; i <= n; i++)
  {
    for (char ch = 'A'; ch <= 'A' + i; ch++)
    {
      cout << ch << " ";
    }
    cout << endl;
  }
}

void print15(int n)
{
  for (int i = 0; i <= n; i++)
  {
    for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
    {
      cout << ch << " ";
    }
    cout << endl;
  }
}

void print16(int n)
{
  for (int i = 0; i < n; i++)
  {
    char ch = 'A' + i;
    for (int j = 0; j <= i; j++)
    {
      cout << ch << " ";
    }
    cout << endl;
  }
}

void print17(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    // charecrters
    char ch = 'A';
    int breakpoint = (2*i+1)/2;
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      cout << ch;
      if(j <= breakpoint ) ch++;
      else ch--;
    }
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  print17(n);
}
