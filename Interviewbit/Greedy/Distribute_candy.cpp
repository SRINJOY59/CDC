int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int>leftpass(n, 1);
    vector<int>rightpass(n, 1);
    for(int i = 1;i<n;i++){
        if(A[i] > A[i-1]){
            leftpass[i] = leftpass[i-1] + 1; 
        }
    }
    for(int i = n-2;i>=0;i--){
        if(A[i] > A[i+1]){
            rightpass[i] = rightpass[i+1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans += max(leftpass[i], rightpass[i]);
    }
    return ans;
}
