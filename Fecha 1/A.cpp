#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long ll;
int F[MAXN];
ll A[MAXN];
int main(){
    ll S = 0;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        S+=A[i];
        F[A[i]]++;
    }
    ll R = 0, aux;
    int tN = N;
    for(int i=0;i<N;i++){
        aux = (A[i] - 1) * F[A[i] - 1] + A[i] * (F[A[i]] - 1) + (A[i] + 1) * F[A[i] + 1];
        ll aS = S - aux;
        int atN = tN - (F[A[i]] + (F[A[i] - 1] - 1) + F[A[i] + 1]);
        if(atN == 1) goto skip;
        R+= (aS - (A[i] * atN));
        skip:
        tN--;
        S-=A[i];
        F[A[i]]--;
    }
    cout << R << "\n";
}
