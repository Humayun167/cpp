#include <iostream>
int main(){
    std::cout <<"Hello boy";


    // user input
    int num;
    
    std::cout <<"Enter your number";
    std::cin>> num;
    std::cout<<"your number is: "<<num <<std::endl;

    // If else

    if (num % 2 ==0){
        std::cout<<"even" <<std::endl;
    }
    else{
        std::cout<<"odd" <<std::endl;
    }

    // loop
      
    int a[6],i;
     std::cout <<"enter the 6 number : ";
     for(i=0l; i<6; i++){
        std::cin>>a[i];
     }

     std::cout<<"reverse number is: ";
     for(i=5; i>0; i--){
        std::cout<<a[i]<<" ";
     }



}