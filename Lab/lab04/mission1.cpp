#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


template <typename T> 
void selectionSort(T a[]) {
    for(int i = 0; i < 9; i++) {
        int minindex = i;
        for(int j = i+1 ; j < 10; j++) {
            if(a[j] < a[i]) {
                minindex = j;
            }
        }
        swap(a[i], a[minindex]);
    }
    return ;
}
int main() {
    int intarr[10] = {10,9,8,7,6,5,4,3,2,1};
    double doublearr[10] = {10.1,9.9,8.8,7.7,6.6,5.5,4.4,3.3,2.2,1.1}; 
    
    printf("int date items in original order\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", intarr[i]);
    }
    printf("\n");
    printf("int date items int ascending order\n");
	selectionSort(intarr);
    for(int i = 0; i < 10; i++) {
        printf("%d ", intarr[i]);
    }
    printf("\n");
    
    
    printf("double date items in original order\n");
    for(int i = 0; i < 10; i++) {
        printf("%.1lf ", doublearr[i]);
    }
    printf("\n");
    printf("double date items int ascending order\n");
	selectionSort(doublearr);
    for(int i = 0; i < 10; i++) {
        printf("%.1lf ", doublearr[i]);
    }
    printf("\n");
    return 0;
}
