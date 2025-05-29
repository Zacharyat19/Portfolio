#include "./vector.hpp"
#include <vector>
#include <iostream>

using std::exception;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   
   std::cout << "Our vector size: " << v.size() << std::endl;
   std::cout << "STL vector size: " << stdv.size() << std::endl;

   std::cout << "\nOur vector []: " << v[0] << std::endl;
   std::cout << "STL vector []: " << stdv[0] << std::endl;

   std::cout << "\nOur vector at(): " << v.at(0) << std::endl;
   std::cout << "STL vector at(): " << stdv.at(0) << std::endl;

   try {
      std::cout << "\nOur vector at() eception: " << v.at(1) << std::endl;
      //std::cout << "STL vector at() eception: " << stdv.at(1) << std::endl;
   } catch(exception& e) {
      std::cout << e.what() << std::endl;
   }

   return 0;
}
