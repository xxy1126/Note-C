
#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
using namespace std;

class Matrix {
    private:
        int n,m;
        int a[100][100];
    public:
        Matrix(int a, int b);
        friend bool operator == (const Matrix &a, const Matrix &b); 
        friend bool operator != (const Matrix &a, const Matrix &b);
        friend Matrix operator + (const Matrix &a, const Matrix &b);
        friend Matrix operator - (const Matrix &a, const Matrix &b);
        friend Matrix operator * (const Matrix &a, const Matrix &b);
        friend void operator << (ostream &output, const Matrix &a);
        friend void operator >> (istream &input, Matrix &a);
};

#endif