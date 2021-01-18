// Exercise 7: Recursive powers of integer numbers 

#include <iostream>
using namespace std; 

int x = 0; 
int power (int a, int n){
  if (n==0){
    return 1;
  }
  else{
    return a * power(a,n-1);
  } 
return 0;
}

int main(){
  int a,n,x; 
  cout << "Enter an integer a: " ; 
  cin >> a; 
  cout << "Enter a non negative integer n: ";
  cin >> n;
  cout << a << " to the power of "<< n << " is " << power(a,n) << endl;
  cout << x << " recursive calls were needed " << endl;
}
