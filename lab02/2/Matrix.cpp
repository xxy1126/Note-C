#include <iostream>
#include <cstdio>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int x,int y) {
    n=x;
    m=y;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j]=0;
        }
    }
} 

bool operator == (const Matrix &a, const Matrix &b) {
    if(a.m != b.m || a.n != b.n) return 0;
    for(int i=1;i<=a.m;i++) {
        for(int j=1;j<=a.n;j++) {
            if(a.a[i][j] != b.a[i][j]) return 0;
        }
    }
    return 1;
} 

bool operator != (const Matrix &a, const Matrix &b) {
    if(a==b) return 0;
    else return 1;
}

Matrix operator + (const Matrix &a, const Matrix &b) {
    Matrix c=Matrix(a.m, a.n);
    for(int i=1;i<=a.m;i++) {
        for(int j=1;j<=a.n;j++) {
            c.a[i][j]=a.a[i][j]+b.a[i][j];
        }
    }
    return c;
}
    

Matrix operator - (const Matrix &a, const Matrix &b) {
    Matrix c=Matrix(a.m, a.n);
    for(int i=1;i<=a.m;i++) {
        for(int j=1;j<=a.n;j++) {
            c.a[i][j]=a.a[i][j]-b.a[i][j];
        }
    }
    return c;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c=Matrix(a.m,b.n);
    for(int i=1;i<=a.m;i++) {
        for(int j=1;j<=b.n;j++) {
            c.a[i][j]=0;
            for(int k=1;k<=a.n;k++) {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
            }
        }
    }
    return c;
}

void operator << (ostream &output, const Matrix &a) {
    for(int i=1;i<=a.n;i++) {
        for(int j=1;j<=a.m;j++) {
            output<<a.a[i][j]<<" ";
        }
        output<<endl;
    }
}
void operator >> (istream &input, Matrix &a) {
    for(int i=1;i<=a.n;i++) {
        for(int j=1;j<=a.m;j++) {
            input >> a.a[i][j];
       }
    }
}