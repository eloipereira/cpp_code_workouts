#include<iostream>
#include<map>
#include<chrono>
#include<ctime>
#include<vector>

using namespace std;


// Brute force solution
// Complexitiy T(n) = 2T(n-1) + O(1) <=> T(n) = O(2^n)

int fib_bf(const int& n){
  if (n <= 1){
    return n;
  } else {
    return fib_bf(n-1) + fib_bf(n-2);
  }
}

// Dynamic programming solution - bottom-up
// Complexity: O(n)

int fib_dp(const int& n){
  int fibs[n+1];
  fibs[0] = 0;
  fibs[1] = 1;

  for (int i = 2; i <= n; i++){
    fibs[i] = fibs[i-1] + fibs[i-2];
  }
  return fibs[n];
}

// Dynamic programming solution - top-down (memoization)
// Complexity: O(n)

const int NIL = -1;

int fib_memo(const int& n, vector<int>& memo){
  if (memo[n] == NIL){
    if (n <= 1){
      memo[n] = n;
    } else {
      memo[n] = fib_memo(n-1,memo) + fib_memo(n-2,memo);
    }
  }
  return memo[n];
}

int main(){
  int n;
  cout << "Insert number: ";
  cin >> n;
  cout << endl;
  cout << "Brute-force approach" << endl;
  clock_t t0 = clock();
  cout << fib_bf(n) << endl;

  clock_t t1 = clock();
  cout << "Time: " << t1-t0 << endl;
  
  cout << "Dynamic programming approach - bottom-up" << endl;
  t0 = clock();
  cout << fib_dp(n) << endl;
  t1 = clock();
  cout << "Time: " << t1-t0 << endl;


  cout << "Dynamic programming approach - top-down (memoization)" << endl;
  t0 = clock();
  
  vector<int> memo;
  for (int i =0; i <=n; i++){
    memo.push_back(NIL);
  }
  
  cout << fib_memo(n,memo) << endl;
  t1 = clock();
  cout << "Time: " << t1-t0 << endl;
  return 0;
}
