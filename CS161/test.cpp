//comment
#include <iostream>
#include <cmath>

#define elements 4


void fill_arrays(int x[], int y[]) {

    for(int i = 0; i < elements; i++){
        std::cout << "Enter an element for x: ";
        std::cin >> x[i];
        std::cout << "Enter an element for y: ";
        std::cin >> y[i]; 
    } 
}



void sum_elements(int x[], int y[], int z[]) {
    for(int i = 0; i < elements; i++) {
        z[i] = x[i] + y[i];
    }
}


int sqrt_of_sum(int z[]) {
    int sum = 0;
    for(int i = 0; i < elements; i++){
        sum = sum + z[i];
    }
    return sqrt(sum);
}


int main() {
    int x[elements], y[elements], z[elements];

    fill_arrays(x,y);
    sum_elements(x,y,z);

    std::cout << "Square root of the sum: " << sqrt_of_sum(z);

    return 0;
}