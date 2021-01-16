// exercise 4: Creating Floyd triangle 
#include <iostream>
using namespace std;


void floyd(int n)
{
  int i, j, s;
  s = 1;
  i = 0;
  j = 0;
  while (i<n)
{
  j = 0;
  while (j<i+1)
  {
  cout << s << " ";
  s += 1;
  j += 1;

  }
  cout << endl;
  i += 1;
  }
}

int main()
{
  int n;
  cout << "choose n:  " << endl;
  cin >> n;
  floyd(n);
  return 0;

}