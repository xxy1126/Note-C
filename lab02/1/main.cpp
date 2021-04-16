#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAXN=3e4+10;
using namespace std;

int a[MAXN],b[MAXN],c[MAXN];

void input() {
    freopen("random.txt","r",stdin);
    for(int i=1;i<=30000;i++) {
        cin>>a[i];
        c[i]=a[i];
    }
    fclose(stdin);
}

void update(int l,int r) {
    int mid=(l+r)>>1;
    int left=l,right=mid+1,cnt=0;
    while(left<=mid && right<=r) {
        if(a[left]<=a[right]) {
            b[++cnt]=a[left];
            left++;
        } else {
            b[++cnt]=a[right];
            right++;
        }
    }

    while(left<=mid) {
        b[++cnt]=a[left++];
    }
    while(right<=r) {
        b[++cnt]=a[right++];
    }

    cnt=0;
    for(int i=l;i<=r;i++) {
        a[i]=b[++cnt];
    }
}


void mergeSort(int l,int r) {
    if(l==r) {
        return ;
    }

    int mid=(l+r)>>1;
    mergeSort(l,mid);
    mergeSort(mid+1,r);

    update(l,r);
}


void output() {
    freopen("mergeSort.txt","w",stdout);
    
    for(int i=1;i<=30000;i++) {
        cout<<a[i]<<" ";
    }

    fclose(stdout);
}

int main() {
    input();

    mergeSort(1,30000);

    output();

}
