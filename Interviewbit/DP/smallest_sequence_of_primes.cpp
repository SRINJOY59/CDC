#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int>answer;
    int i = 0, x = 0, y = 0, z = 0;
    answer.push_back(1);
    while(i < D){
        int mini = min(A*answer[x], min(B*answer[y], C*answer[z]));
        answer.push_back(mini);
        i++;
        if(mini == A*answer[x]) x++;
        if(mini == B*answer[y]) y++;
        if(mini == C*answer[z]) z++;
    }    
    answer.erase(answer.begin());
    return answer;
}
