#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int A[MAXN];

int main(){
    int N, T;
    cin >> N >> T;
    for(int i=0;i<N;i++) cin >> A[i];
    sort(A, A + N);
    int SI = 0, SD = 0, I = 0, D = 0;
    for(int i = 0, j = N - 1; i < N && j >= 0; i++, j--){
        if(SI + A[i] < T){
            I++;
            SI+=A[i];
        }
        if(SD + A[j] < T){
            D++;
            SD+=A[j];
        }
    }
    cout << D << " " << I << "\n";
}
