#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll R = 0, C = 0;
    string N;
    cin >> N;
    for(int i=0;i<N.size();i++){
        if(N[i] == '1'){
            R+= (1 + C);
            C++;
        }
    }
    cout << R << "\n";
}
