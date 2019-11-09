#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
  matrix A(3,3),B(3,3);

  //output(A); cout<<endl;

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
  {
      int x;
      cin>>x;
      B.set_matrix(i,j,x);
  }
  //output(B); cout<<endl;
  if(B.symatric())
    cout<<"yes";
  else cout<<"no";

}
