#include <sys/time.h>
#include <cstdlib>
#include <iostream>

int fibIter(int n);
int fibRecur(int n);

int main() {
    typedef struct timeval time;
    time stop, start;
    gettimeofday(&start, NULL); 

    std::cout << fibRecur(5) << std::endl;

    gettimeofday(&stop, NULL);
    if(stop.tv_sec > start.tv_sec)
        std::cout << "Seconds: " << stop.tv_sec-start.tv_sec <<
        std::endl;
    else
        std::cout << "Micro: " << stop.tv_usec-start.tv_usec <<
        std::endl;

    return 0;
} 

int fibIter(int n) {
    if(n <= 1) {
        return n;
    }

    int x = 0, y = 1;
    for(int i = 0; i < n - 1; i++) {
        int z = x + y;
        x = y;
        y = z;
    }
    std::cout << y << std::endl;
    return y;
}

int fibRecur(int n) {
    if((n == 1) || (n == 0)) {
      return(n);
   }else {
      return(fibRecur(n - 1) + fibRecur(n - 2));
   }
}