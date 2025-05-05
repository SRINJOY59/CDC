#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(mid > start && arr[mid-1] == target){
                return mid-1;
            }
            else if(mid < end && arr[mid+1] == target){
                return mid+1;
            }
            else if(target < arr[mid])
                end = mid-2;
            else
                start = mid+2;
        }
        return -1;
    }
};

int main(){
    int n, target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    cout<<sol.findTarget(arr, target)<<endl;
    return 0;
}