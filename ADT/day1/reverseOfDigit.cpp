#include<iostream>
using namespace std;

int reverse(int num,int rev=0){//returns the reverse of digit
   if(num==0)return rev;
   return  reverse(num/10,rev*10+(num%10));
}
int main(){
    int num;
    cin>>num;
    int rev=reverse(num);
    cout<<"Reversed number: "<<rev;
    if(rev==num){
        cout<<"\nThe number is a palindrome.";
    }
    else{
        cout<<"\nThe number is not a palindrome.";
    }
}