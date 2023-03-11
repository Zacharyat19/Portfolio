/*
 * This program should compute the first n values in the Fibonacci sequence
 * for a user-specified value of n.
 *
 * Once compiled, you can run this program like so (here, we're using n = 7):
 *   ./debug_demo 7
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * This function computes the Fibonacci sequence up to the n'th value and
 * stores the sequence in the provided array, which should be pre-allocated.
 */
void compute_fib_seq(int* fib_seq, int n) {
  int prev_fib, prev_prev_fib;
  fib_seq[0] = 1;
  for (int i = 0; i < n; i++) {
    prev_fib = fib_seq[i-1];
    prev_prev_fib = fib_seq[i-2];
    fib_seq[i] = prev_fib + prev_prev_fib;
  }
}


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Error: must specify a value for n." << endl;
    cout << "usage: " << argv[0] << " <n>" << endl;
    return 1;
  }

  int n = strtol(argv[1], NULL, 0);
  if (n <= 0) {
    cout << "Error: n must be a positive integer value." << endl;
    cout << "usage: " << argv[0] << " <n>" << endl;
    return 1;
  }

  int* fib_seq;
  compute_fib_seq(fib_seq, n);
  cout << "The first " << n << " digits of the Fibonacci sequence are:";
  for (int i = 0; i < n; i++) {
    cout << "  " << fib_seq[i];
  }
  cout << endl;

  return 0;
}