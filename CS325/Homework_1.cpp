/**Name: Zach Taylor
 * Email: taylzach@oregonstate.edu
 * 
 * Maximum Subarray Problem
 * Given an array of N integers, what is the maximum sum subarray in O(n), O(n^2), O(n^3), and O(n log n) time
 **/

#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <string>
#include <chrono>
using namespace std::chrono;

//Implementation of O(n^3)-time
int max_subarray_enumeration(std::vector <int> array, int a) {
    int max_sum = INT_MIN;
    for(int i = 1; i <= a; i++) { //Configure subarray size
        for(int j = 0; j < a; j++) { //Start index of subarray
            if((i + j) > a) { //If the subarray is out of bounds of the array, break
                break;
            }
            int sum = 0;
            for(int k = j; k < (i + j); k++) { //Add elements of subarray
                sum += array[k];
            }
            max_sum = std::max(max_sum, sum); //Compare sums and return the largest one found
        }
    }
    return max_sum;
}

//Implementation of O(n^2)-time
int max_subarray_iteration(std::vector<int> array, int a) {
    int max_sum = INT_MIN;
    for(int i = 0; i < a; i++) { //Start index
        int sum = 0;
        for(int j = 1; j <= a; j++) { //Configure subarray size
            if((i + j) > a) {
                break;
            }
            sum += array[ i + j - 1]; //The sum of the subarray is the sum of the previous array plus the new index
            max_sum = std::max(max_sum, sum);
        }
    }
    return max_sum;
}

//Implementation of O(n log n)-time
int max_subarray_simplification_delegation(std::vector<int> array, int a) {
    if( a == 1) {
        return array[0];
    }

    int m = a/2;
    int left = max_subarray_simplification_delegation(array, m);

    auto begin = array.begin() + m;
    auto stop = array.end();
    std::vector<int> right_array(array.size() - m);
    std::copy(begin, stop, right_array.begin());

    int right = max_subarray_simplification_delegation(right_array, a - m);
    int left_sum = INT_MIN; 
    int right_sum = INT_MIN;
    int sum = 0;

    for(int i = m; i < a; i++) {
        sum += array[i];
        right_sum = std::max(right_sum, sum);
    }

    sum = 0;
    for(int i = (m - 1); i >= 0; i--) {
        sum += array[i];
        left_sum = std::max(left_sum, sum);
    }

    int max_sum = std::max(left, right);
    return std::max(max_sum, left_sum + right_sum);
}

//Implementation of O(n)-time
int max_subarray_recursion_inversion(std::vector<int>& array, int a, int sum, int max_sum) {
    if(a == array.size()) {
        return max_sum;
    }

    sum += array[a];
    if(sum < 0) {
        sum = 0;
    }
    max_sum = std::max(max_sum, sum);
    max_subarray_recursion_inversion(array, a + 1, sum, max_sum);
}

int main() {
    std::ifstream fin;
    fin.open("num_array_1000.txt");
    int x;

    std::vector <int> data;

    while(fin >> x) {
        data.push_back(x);
    }
    fin.clear();
    fin.close();
    
    int n = data.size();
    int max_sum = INT_MIN;
    int sum = 0;

    auto start = high_resolution_clock::now();
    int a = max_subarray_enumeration(data, n);
    std::cout << "n^3 max sum is: " << a << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Runtime: " << duration.count() << " microseconds" << std::endl;
    std::cout << "\n";

    start = high_resolution_clock::now();
    a = max_subarray_iteration(data, n);
    std::cout << "n^2 max sum is: " << a << "\n";
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Runtime: " << duration.count() << " microseconds" << std::endl;
    std::cout << "\n";

    start = high_resolution_clock::now();
    a = max_subarray_simplification_delegation(data, n);
    std::cout << "n log n max sum is: " << a << "\n";
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Runtime: " << duration.count() << " microseconds" << std::endl;
    std::cout << "\n";

    start = high_resolution_clock::now();
    a = max_subarray_recursion_inversion(data, 0, sum, max_sum);
    std::cout << "n! max sum is: " << a << "\n";
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Runtime: " << duration.count() << " microseconds" << std::endl;

    return 0;
}