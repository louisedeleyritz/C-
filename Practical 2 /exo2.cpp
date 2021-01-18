#include <iostream>
using namespace std; 

void position(); 
  
int main() {

  position(); 
  return 0; 

}
void position()
{
  int n;   
  double v, a, x0, x, t, m; 
  m=0.0; 
  cout << "Enter the initial position, the speed and the acceleration: \n";
  cin >> v >> a >> x0; 
  cout << "How many times you want to display the position of the moving body? \n"; 
  cin >> n; 
  cout << "How often (in seconds) you want to update the position of the moving object?\n"; 
  cin >> t; 
  cout << "Acceleration: " << a << " Initial speed: " << v << " Initial position: " << x0 << " Number of times: " << n << " Delta t: " << t << "\n";

  for (int i=0;i<n;i=i+1){
    x = x0 + v*m + (a/2)*m*m;


  cout << "At time " << m <<  " the position is " << x << "\n";

  m += t; 
  
}