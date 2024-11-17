#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);

    long long N, M, K;
    cin >> N >> M >> K;

    
    vector<pair<long long, long long>> health(N);
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        pair<long long, long long> temp = {i, num};
        health[i] = temp;
    }

    long long X = 628900;   //Change value X here to find the area of power needed

    
    if(K == 1){
        long long maxDmgToDo = 0;
        int pos = 0;
        
        for(long long i = 0; i < N; i++){
            long long h = health.at(i).second;

            long long dmgToDo = (h + i*i)/M;

            if(dmgToDo > maxDmgToDo){
                maxDmgToDo = dmgToDo;
                pos = i;
            }
            // cout << i << " " << dmgToDo << " " << maxDmgToDo << endl;
        }

        X = maxDmgToDo + 1;

        cout << X << endl;

        return 0;
    }


    bool allDestroyed = false;
    while(!allDestroyed){

        vector<pair<long long, long long>> h2(health);
        int K2 = K;
        int pos = 0;

        for(long long i = pos; i < N && K2 > 0; i = pos){
            int c = 0;
            for(long long j = i; j < N; j++){
                long long dmg = M * X - (j - i)*(j - i);
                if(0 > dmg){
                    break;
                }

                h2[j].second -= dmg;
                if(h2[j].second > 0 && c == 0){
                    pos = j;
                    c++;
                }
                 
            }
            K2--;
            if(h2[pos].second <= 0 && h2[N - 1].second <= 0){
                allDestroyed = true;
                X--;
                break;
            }
        }
        cout << X << endl;
        X++;
    }

    cout << X << endl;

    return 0;
}