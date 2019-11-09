#ifndef MATRIX_H
#define MATRIX_H


class matrix
{
    public:
        matrix();
        matrix(int r,int c);
        matrix(const matrix & m);
        matrix operator +(const matrix &m)const;
        void allocate_matrix(int ,int );
        virtual ~matrix();
        void  operator = (const matrix & mat) ;

        void  set_matrix (int nr,int nc,int num);
        matrix add (const matrix &mat)const ;
         friend void  output (const matrix & );
         matrix multplie (const matrix & )const ;
         matrix operator * (const matrix & mat)const;
         matrix &  operator * ( int n);
        bool symatric ();
         //int matrix operator [] (int i,int j );
    protected:

    private:
        int row,col;
        int **data;
};

#endif // MATRIX_H
