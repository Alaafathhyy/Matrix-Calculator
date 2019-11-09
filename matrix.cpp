#include "matrix.h"
#include <iostream>
using namespace std;

matrix::matrix()
{
    col=0;
    row=0;
    data=0;
}
void matrix ::allocate_matrix(int row,int col)
{
    data= new int*[row];
    for(int i=0; i<row; i++)
        data[i]=new int[col];
}
matrix :: matrix (const matrix &m)
{
    row=m.row;
    col=m.col;
    allocate_matrix(m.row,m.col);
}
void  matrix:: set_matrix (int nr,int nc,int num)
{
    data[nr][nc]=num;
}
void  output ( const matrix &mat)
{
    for(int i=0; i<mat.row; i++)
    {

        for(int j=0; j<mat.col; j++)
        {
            cout<<mat.data[i][j];
        }
        cout<<endl;
    }
}
matrix matrix ::multplie (const matrix & mat)const
{
    matrix new_matrix (col,mat.row);
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<col; j++)
        {
            new_matrix.data[i][j]=0;
            for(int k=0; k<col; k++)
            {
                new_matrix.data[i][j]+=data[i][k]*mat.data[k][j];
            }
        }
    }
    return new_matrix;
}
matrix matrix ::operator * (const matrix & mat)const
{
    matrix new_matrix (col,mat.row);
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<col; j++)
        {
            new_matrix.data[i][j]=0;
            for(int k=0; k<col; k++)
            {
                new_matrix.data[i][j]+=data[i][k]*mat.data[k][j];
            }
        }
    }
    return new_matrix;

}
matrix & matrix :: operator * ( int n)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            data[i][j]*n;
            return  *this ;

}
bool matrix ::symatric ()
{
    for (int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(data[i][j]!=data[j][i])
                return false ;
        }
    }
    return true ;
}
matrix matrix:: operator +(const matrix &mat )const
{
    matrix new_matrix(row,col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        {
            new_matrix.data[i][j]=data[i][j]+mat.data[i][j];
        }
    return new_matrix ;
}
matrix matrix :: add (const matrix &mat)const
{
    matrix new_matrix(row,col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        {
            new_matrix.data[i][j]=data[i][j]+mat.data[i][j];
        }
    return new_matrix ;
}

matrix ::matrix(int row,int col)
{
    this->row=row;
    this->col=col;
    allocate_matrix(row,col);

}
void matrix :: operator = (const matrix & mat)
{                                                   //act like the copy constructor
    row=mat.row;
col=mat.col;
for(int i=0;i<mat.row;i++)
    for(int j=0;j<mat.col;j++)
    data[i][j]=mat.data[i][j];

}
matrix::~matrix()
{
    for(int i=0; i<row; i++)
        delete data[i];
    delete data;
}
