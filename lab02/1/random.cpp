#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main() {
    freopen("random.txt","w",stdout);
    srand(time(0));
    for(int i=1;i<=30000;i++) {
        cout<<rand()%1000000<<" ";
    }
    fclose(stdout);
    return 0;
}