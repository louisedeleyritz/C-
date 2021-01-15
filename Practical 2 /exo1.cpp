//Point in a circle 
#include <iostream>
using namespace std; 

bool belongs_to_circle (int x, int y, int z, int w, int radius) // declaration of the function

{ if (((x - z)*(x - z)+ (y - w)*(y - w)) <= radius*radius)// The function verifies whether a given point (with coordinates x and y) belongs to the circle with a given center (with coordinates z and w) and radius. 
return true;  

else 

return false;
}  

 int main() {

   int z = 4, w=1, radius = 2; //example
   int x,y; 
   cout << "x:"; 
   cin >> x; 
   cout << "y:"; 
   cin >> y; 

if (belongs_to_circle(x,y,z,w,radius))
{

    cout<< "(x,y) belongs to the circle" << endl; 
    else 
    cout << " (x,y) does not belong to the circle";
}
   
  
  
}
