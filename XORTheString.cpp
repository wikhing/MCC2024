#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    

    int n, k;
    cin >> n >> k;

    string t;
    cin >> t;
    
    long long beauty = 0;
    if(k == 0){
        for(int i = 0; i < t.size(); i++){
            for(int j = i + 1; j < n; j++){
                if(j - i + 1 >= 2){
                    string s = t.substr(i, j - i + 1);
                    for(long long j = 1; j < s.size(); j++){
                        if(s.at(j) == s.at(j - 1)){
                            beauty++; 
                            beauty %= 998244353;
                        }
                    }
                }
            }
        }
    
        cout << beauty;

        return 0;
    }

    int totalComb = 0;
    vector<string> comb;
    for (int i = 0; i < n; ++i) {
        totalComb += i;
        for (int j = i + 2; j <= n; ++j) {
            comb.push_back(t.substr(i, j - i));
        }
    }

    sort(comb.begin(), comb.end());
    auto it = unique(comb.begin(), comb.end());
    // comb.erase(it, comb.end());
    comb.erase(comb.begin() + totalComb, comb.end());
    
    beauty = 0;
    for(int i = 0; i < comb.size(); i++){
        string str = comb.at(i);
        string s = "";
        int k2 = k;

        bool allEqual = true;
        for(int j = 1; j < str.size(); j++){
            if(str.at(j) != str.at(j - 1)){
                allEqual = false;
                break;
            }
        }

        while(k2 > 0 && !allEqual){
            for(int j = 0; j < str.size() - 1; j++){
                s.push_back(str[j]);
                s.push_back((str[j] == str[j + 1]) ? '0' : '1');  // XOR operation
            }
            s.push_back(str.back());

            str = s;
            s = "";
            k2--;
        }

        if(allEqual){
            long long val = str.size();

            while(k2 > 0){
                val = (val * 2) - 1;
                k2--;
            }
            beauty += val - 1;
            beauty %= 998244353;
        }else{
            for(long long j = 1; j < str.size(); j++){
                if(str.at(j) == str.at(j - 1)){
                    beauty++; 
                    beauty %= 998244353;
                }
            }
        }
    }
    

    cout << beauty << endl;

    return 0;
}