#include <iostream>
#include <fstream>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    
    ofstream out("output.txt");

    for(int a = 0; a < T; a++){
        long long n, m, A, B;
        cin >> n >> m >> A >> B;

        if(A == n && B <= m|| B == m && A <= n|| B == n && A <= m|| A == m && B <= n) out << "YES" << endl;
        else out << "NO" << endl;
    }

    out.close();
    
    return 0;
}