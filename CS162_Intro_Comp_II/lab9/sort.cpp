#include <iostream>
#include <ctime>
#include <cstdlib>

void sort(int arr[], int first, int last);
void load(int a[], int length);
void print(int a[], int length);
void merge(int arr[], int first, int m, int last);

int main() {
    int length;

    while(true) {
        std::cout << "Enter an array size greater than zero but less than twenty: ";
        std::cin >> length;

        if(length < 0 || length > 20) {
            std::cout << "Invalid size" << std::endl;
        } else {
            break;
        }
    }

    std::cout << "Array before sort: " << std::endl;
    int *arr = new int[length];
    load(arr, length);
    print(arr, length);

    std::cout << "\nArray after sort: " << std::endl;
    int *temp = new int[length];
    for(int i = 0; i < length; i++) {
        temp[i] = arr[i];
    }
    sort(temp, 0, length - 1);
    print(temp, length);
    std::cout << std::endl;

    std::cout << "All prime numbers: " << std::endl;
    for (int i = 0; i < length; i++) {
        bool prime = true; 
        for (int j = 2; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                prime = false;
                break; 
            }
        }   
        if(prime) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;

    delete []arr;
    delete []temp;
}

void sort(int arr[], int first, int last) {
    if (first < last) { 
        int m = first + (last - first) / 2; 

        sort(arr, first, m); 
        sort(arr, m + 1, last); 
  
        merge(arr, first, m, last); 
    }
}

void merge(int arr[], int first, int m, int last) {
    int i, j, k; 
    int n1 = m - first + 1; 
    int n2 =  last - m; 
  
    int temp[n1];
    int temp2[n2]; 
  
    for (i = 0; i < n1; i++) { 
        temp[i] = arr[first + i]; 
    }
    for (j = 0; j < n2; j++) {
        temp2[j] = arr[m + 1+ j]; 
    }
  
    i = 0;
    j = 0;
    k = first;

    while (i < n1 && j < n2) { 
        if (temp[i] <= temp2[j]) { 
            arr[k] = temp[i]; 
            i++; 
        } else { 
            arr[k] = temp2[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = temp[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = temp2[j]; 
        j++; 
        k++; 
    } 
}

void load(int a[], int length) {
    srand((unsigned) time(0));

    for(int i = 0; i < length; i++) {
        int j = (rand() % 50) + 1;
        a[i] = j;
    }
}

void print(int a[], int length) {
    for(int i = 0; i < length; i++) {
        std::cout << a[i] << " ";
    }
}
