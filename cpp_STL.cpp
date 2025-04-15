#include <bits/stdc++.h>
using namespace std;

// int sum(int a,int b){
//     return a + b;
// }


//Pair 

void expaline_Pair(){
    // pair<int,int> p={1,3};
    // cout << p.first<<" " << p.second;

    pair<int, pair<int ,int>> p= {1,{3,4}};
    cout<< p.first <<" "<< p.second.second;

}

// int main(){
//       expaline_Pair();
// }

// using Vectior

void explain_vector(){ 
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
}


void stack_expain()
{
    stack<int> st;
    st.push(1);
    
cout<< st.top();
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

     cout << "Queue elements: ";
     // This removes the front element
     while (!q.empty()) {
        cout << q.front() << " ";
        q.pop(); // This removes the front element
    }
    }