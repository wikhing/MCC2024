#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    
    vector<pair<long long, long long>> scores(n);
    vector<long long> values(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        scores[i] = {a, b};
        values[i] = a + b;
    }

    long long X = 0, Y = 0;
    int maxVidx = 0;
    for(int i = 0; i < n / 2; i++){
        long long maxValue = LLONG_MIN;

        for(int j = 0; j < scores.size(); j++){
            if(values.at(j) > maxValue){
                maxValue = values[j];
                maxVidx = j;
            }
        }
        X += scores.at(maxVidx).first;
        scores.erase(scores.begin() + maxVidx);
        values.erase(values.begin() + maxVidx);

        maxValue = LLONG_MIN;
        for(int j = 0; j < scores.size(); j++){
            if(values.at(j) > maxValue){
                maxValue = values[j];
                maxVidx = j;
            }
        }
        Y += scores.at(maxVidx).second;
        scores.erase(scores.begin() + maxVidx);
        values.erase(values.begin() + maxVidx);
    }

    cout << X-Y << endl;

    return 0;
}