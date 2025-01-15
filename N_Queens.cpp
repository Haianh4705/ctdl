#include <iostream>
using namespace std;
 
const int maxn = 8; // Q
bool row[maxn+1], col[maxn+1], dia1[(maxn+1)*2], dia2[(maxn+1)*2];
int ans = 0;
 
void backtrack(int n) {
    if (n > maxn) {ans++; return;}
    for (int i = 1; i<=maxn; i++) {
        if (row[n] == false && col[i] == false && dia1[n-i+maxn] == false && dia2[n+i] == false) {
            row[n] = col[i] = dia1[n-i+maxn] = dia2[n+i] = true;
            backtrack(n+1);
            row[n] = col[i] = dia1[n-i+maxn] = dia2[n+i] = false;
        }
    }
}

int main() {
    backtrack(1);
    cout << ans;
    return 0;
}
