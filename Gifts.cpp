#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<long long> guests(n);
    vector<long long> sorted(n);
    vector<long long> haveGifts(n);

    for(int i = 0; i < n; i++){
        cin >> guests[i];
        sorted[i] = guests[i];
    }
    
    sort(sorted.begin(), sorted.end());
    // auto it = unique(sorted.begin(), sorted.end());
    // sorted.erase(it, sorted.end());

    long long c = 0;
    for(int i = 0; i < n; i++){
        c = sorted[i];
        cout << c << " " << m << endl;
        for (int j = 0; j < n; j++){
            if(guests[j] == c && m > 0 && haveGifts[j] == 0){
                haveGifts[j] = 1;
                m--;
            }
        }
        if(m == 0) break;
    }

    ofstream out("output.txt");
    
    for(int i = 0; i < n; i++){
        out << haveGifts[i] << " ";
    }

    out.close();
    
    return 0;
}