#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
using namespace std;

class NotNumber: public exception {
    public: 
        NotNumber(bool x=0) {
            error = x;
        }
        virtual char* what() {
            if(error) {
                printf("INVALID INPUT: non-integer deteced.\n");
            }
        }
    private: 
        bool error;
};

int main() {
    while(1) {
        char s[100];

        printf("Please enter a number (end-of-file to terminate): ");
        if(scanf("%s",s) == EOF) {
            return 0;
        }
        try {
            int len = strlen(s), sum = 0, flag = 1;
            if(s[0] == '-') {
                flag = -1; 
            }
            for(int i = 0; i < len; i++) {
                if(s[i] == '-' && (i == 0)) continue ;
                if(isdigit(s[i])) {
                    sum = sum * 10 + (s[i] - '0');
                } else {
                    throw NotNumber(1); 
                }
            }
            printf("The number entered was %d\n", sum * flag);
        } catch (NotNumber& e){
            e.what();
        }

    }
    return 0;
}
