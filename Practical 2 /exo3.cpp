//*swapping two numbers using call by reference 
#include <iostream>
using namespace std; 
void swap_num(int &i, int &j) {
 
  int temp = i;
  i = j;
  j = temp;
 
}
 
int main() {
  int a, b; 
  cout << "Choose two numbers: "; 
  cin >> a;
  cin >> b ;
 
  swap_num(a, b);
 
  cout << a << " " << b << "\n";
  
 
 }
 