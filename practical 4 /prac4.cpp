#include <iostream>
#include <cmath> 

using namespace std;

double * read_poly1(int &n1){ // the returned value is a pointer to the vector representing the result. 
  cout << "degree of the polynomial: ";
  cin >> n1;
  double * co1 =new double[n1+1]; 
  
  for(int i=0;i<=n1;i++){ 
    cout << "coefficient of degree " << i << ": \n";
    cin >> co1[i];
  }
  return co1;
}

void print_poly1(double * co1, int n1){
  int i; 
  cout << co1[0];
  if(n1>0) 
    cout << " + ";
  for(i=1;i<n1;i++) // for loop adding the coefficient entered in keyboard until the degree of the function is reached. we iterate through the array of coefficient until we reach the chosen degree. 
    cout << co1[i] << "*x^" << i << " + ";
  if(n1>0)
    cout << co1[n1] << "*x^" << i << "\n"; // for the last coefficient. 
  cout << endl;
}

//exercise 1: calculating the polynomial value for a certain position x (returns a real number)

void calculating_poly(double *c, int n)
{
  int x,i;
  double value=0;

  cout <<"Enter value of x: ";
  cin >>x;
  
  for(i=0;i<=n+1;i++)
  { 
    value=value+c[i]*pow(x,i);
  }
cout<<"The value of the first polynomial is: "<< value<<endl;
}

//exercise 2: Calculating the sum of two polynomials (returns a polynomial)

double * poly_sum (double * poly1, int d1, double * poly2, int d2) 
{
  int i,j;
  if (d1<d2)
  {
    for(j=0;j<=d2+1;j++)
    {
      for(i=0;i<=d1+1;i++)
      {
        if (i==j)
        {
          poly2[j]=poly1[i]+poly2[j];
        }

      }
    }

    cout<<"The sum of the two polynomials is: ";
    print_poly1(poly2,d2);
    cout<<endl;
  }
  else
  {
    for(i=0;i<=d1+1;i++)
    {
      for(j=0;j<=d2+1;j++)
      {
        if (i==j)
        {
          poly1[j]=poly1[i]+poly2[j];
        }
      }
    }
     cout<<"The sum of the two polynomials is: ";
    print_poly1(poly1,d1);
    cout<<endl;
}
}

//exercise 3: product of two polynomials (returns one polynomial) 

void poly_product(double *poly1, int d1, double *poly2, int d2)
{
  int i,j;

  double * prod = new double[d1+d2];
// dynamically allocated array
  for (i=0;i<=d1+d2;i++)
  {
    prod[i]=0;
  }

  for(j=0;j<=d2;j++)
  {
    for(i=0;i<=d1;i++)
    { 
      prod[i+j] = prod[i+j]+(poly1[i]*poly2[j]); 
    }
  }
  cout<<"The product of the two polynomials is: ";
    print_poly1(prod,d1+d2);
    cout<<endl;
  
}



int main()
{
  double *poly1,*poly2;
  int x1,x2;
  int x; 

 // calling function
  poly1=read_poly1(x1);
  print_poly1(poly1,x1);


  
  //Exercise 1: calculating polynomial
  calculating_poly(poly1,x1);

  //Displaying the second polynomial
  poly2=read_poly1(x2);
  print_poly1(poly2,x2);


  //Exercise 3: product of two polynomials
  poly_product(poly1,x1,poly2,x2);

 //Exercise 2: sum of two polynomials
 poly_sum(poly1,x1,poly2,x2);
  

  


  delete[] poly1;
  delete[] poly2;
 

  return 0;
}

 
