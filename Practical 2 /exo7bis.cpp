// Exercise 7 bis: Second recursive definition 
#include <iostream>
using namespace std; 

int x = 0, y =0; // global variable

int power(int a, int n){
  if (n==0){
    return 1;
  }
  else{
    x += 1; 
    return a * power(a,n-1);
  } 
return 0;
}

int power2(int a, int n){
  if (n==0){
    return 1;
  }
  else if (n%2==0){
    y+=1; 
    return power2(a,n/2) * power2(a, n/2);
  }
  else if (n%2 != 0){
    y+=1;
    return a * power2(a,n/2) * power2(a, n/2);
  }
return 0; 
}

int main(){
  int a,n; 
  cout << "Enter an integer a: " ; 
  cin >> a; 
  cout << "Enter a non negative integer n: ";
  cin >> n;
  cout << "\n" << a << " to the power of "<< n << " is " << power(a,n) << endl;
  cout << "\n" <<  x << " recursive calls were needed for function 1" << endl;
  cout << endl << a << " to the power of " << n << " is " << power2(a,n) << endl;
  cout << "\n" << y << " recursive calls were needed for function 2 " << endl;
return 0;
}

// With the first version of the power function, the number of recursive calls displayed on the screen in n. 
// With the second version of the power function, we observe that more recursive calls are used. The number of recursive calls follow the following pattern: 2 * (n - 1). We have: 
// n = 1,2,3,4,5,6...
// c = 1,3,3,7,7,7.. 
// With C the number of recursive calls. 