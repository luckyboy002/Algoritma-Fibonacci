#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long fibonacci_recursive(int n) {
 if (n <= 0) {
 return 0;
 } else if (n == 1) {
 return 1;
 } else {
 return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
 }
}

long long fibonacci_dynamic(int n) {
 if (n <= 0) {
 return 0;
 } else if (n == 1) {
 return 1;
 }
 vector<long long> fib(n+1);
 fib[0] = 0;
 fib[1] = 1;
 for (int i = 2; i <= n; i++) {
 fib[i] = fib[i-1] + fib[i-2];
 }
 return fib[n];
}

int main() {
 int values[] = {10, 25, 30, 40, 50};
 cout << "Rekursif:\n";
 for (int n : values) {
 auto start = high_resolution_clock::now();
 long long result_recursive = fibonacci_recursive(n);
 auto stop = high_resolution_clock::now();
 auto duration_recursive = duration_cast<microseconds>(stop - start);
 cout << "Fibonacci(" << n << ") = " << result_recursive << " - Waktu: "
<< duration_recursive.count() << " microseconds\n";
 }
 cout << "\nDynamic Programming:\n";
 for (int n : values) {
 auto start = high_resolution_clock::now();
 long long result_dynamic = fibonacci_dynamic(n);
 auto stop = high_resolution_clock::now();
 auto duration_dynamic = duration_cast<microseconds>(stop - start);
 cout << "Fibonacci(" << n << ") = " << result_dynamic << " - Waktu: " <<
duration_dynamic.count() << " microseconds\n";
 }
 return 0;
}
