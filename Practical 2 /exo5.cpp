// Non-recursive fibonacci 
#include <iostream>
using namespace std;

int fibonacci(int n)
{
  int value,a,b,temp;
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  return 1;
  a = 1;
  b = 1;
  for (int i=2;i<n;i+=1)
  {
    temp = a;
    a = b;
    b = temp + b;
    }

  return b;
  }

int main()
{
  int n;
  cout << "give n " << endl;
  cin >> n;
  cout << fibonacci(n);
  return 0;

}