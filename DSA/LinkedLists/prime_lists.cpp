#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

template<typename T>
vector<T> sieve(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

Node *primeList(Node *head) {
        // code here
    vector<int>primes = sieve(100100);
    Node* temp = head;
    while(temp != NULL){
            
    int num = temp->val;
    if(num == 1 || num == 0){
        temp->val = 2;
        temp = temp->next;
        continue;
    }
    if(binary_search(primes.begin(), primes.end(), num)){
        temp = temp->next;
        continue;
    }
    int upper = upper_bound(primes.begin(), primes.end(), num) - primes.begin();
    int lower = upper - 1;
    int diff1 = abs(primes[lower] - num);
    int diff2 = primes[upper] - num;
    if(diff1 > diff2)
        num = primes[upper];
    else 
        num = primes[lower];
        temp->val = num;
        temp = temp->next;
    }
    return head;
}