#include <iostream>
#include <cstdio>

#include "Matrix.h"

using namespace std;

int main() {
    cout<<"Please enter to matrixs:"<<endl;

    //input first
    cout<<"The first matrix M1's lines n and rows m are:"<<endl;
    
    int a,b;
    cin>>a>>b;
    Matrix M1=Matrix(a,b);

    cout<<"Please enter the matrix by lines:"<<endl;
    cin>>M1;

    //input second
    cout<<"The second matrix M1's lines n and rows m are:"<<endl;
    
    cin>>a>>b;
    Matrix M2=Matrix(a,b);

    cout<<"Please enter the matrix by lines:"<<endl;
    cin>>M2;

    // + 
    cout<<"The + matrix of two matrix: "<<endl;
    cout<<M1+M2;
    // - 
    cout<<"The - matrix of two matrix: "<<endl;
    cout<<M1-M2;
    // * 
    cout<<"The * matrix of two matrix: "<<endl;
    cout<<M1*M2;
    // == 
    if(M1==M2) cout<<"M1 is equal to M2"<<endl;
    else cout<<"M1 is not equal to M2"<<endl;
    // !=
    if(M1!=M2) cout<<"M1 is not equal to M2"<<endl;
    else cout<<"M1 is equal to M2"<<endl;
    return 0;
}