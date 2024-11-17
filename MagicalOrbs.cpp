#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++){
        
        int n;
        cin >> n;

        vector<long long> orbs(n);
        
        for(int i = 0; i < n; i++){
            cin >> orbs[i];
        }

        if(n == 1){
            cout << (orbs[0] % 1000000007) << endl;
            continue;
        }

        sort(orbs.begin(), orbs.end(), greater<>());

        long long power = orbs[0];
        for(int i = 1; i < n; i++){
            power = ((power * 2) + orbs[i]);
            power %= (1000000007);
        }
        
        
        cout << power << endl;
    }

    return 0;
}