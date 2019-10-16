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

void unionSet(int i, int j){
    int x = findSet(i), y = findSet(j);
    if(x != y){
        S--;
        p[x] = y;
    }
}
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
iii V[100005];

int main(){
    int T, N, M, u, v, c;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        initSet(N);
        for(int i=0;i<M;i++){
            scanf("%d %d %d", &u, &v, &c);
            --u, --v;
            unionSet(u, v);
        }
        int R;
        scanf("%d", &R);
        for(int i=0;i<R;i++){
            scanf("%d %d %d", &u, &v, &c);
            --u, --v;
            V[i] = (iii(c,ii(u, v)));
        }
        if(S == 1){
            printf("Thank you, Goodbye\n");
            continue;
        }
        long long ans = 0;
        sort(V, V + R);
        for(int i=0;i<R;i++){
            int x = findSet(V[i].second.first), y = findSet(V[i].second.second);
            if(x != y){
                unionSet(x, y);
                ans+= V[i].first;
                if(S == 1) break;
            }
        }
        if(S > 1){
            printf("You better hire someone else\n");
        }else{
            printf("%lld\n", ans);
        }
    }
}
