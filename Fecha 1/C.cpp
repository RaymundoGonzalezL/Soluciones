#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

int p[MAXN];
int S;
void initSet(int N){
    S = N;
    for(int i=0;i<N;i++) p[i] = i;
}

int findSet(int i){
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
    int x = findSet(i), y = findSet(j);
    if(!isSameSet(x,y)){
        S--;
        p[y] = x;
    }
}

int main(){
    int T, N, M, u, v, c;
    cin >> T;
    while(T--){
        cin >> N >> M;
        initSet(N);
        for(int i=0;i<M;i++){
            cin >> u >> v >> c;
            --u, --v;
            unionSet(u, v);
        }
        bool ok = (S <= 2);
        int R;
        int mini = INT_MAX;
        cin >> R;
        while(R--){
            cin >> u >> v >> c;
            if(ok){
                --u, --v;
                if(!isSameSet(u, v)) mini = min(mini, c);
            }
        }
        cout << mini << "\n";
    }
}
