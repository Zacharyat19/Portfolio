#include <stdlib.h>
#include <stdexcept>

 using std::out_of_range;

template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s = 0;
	     v = NULL;
      }

	  vector(vector &other) {
          s = other.s;
          v = new T[s];
          for(int i = 0; i < s; i++) {
              v.push_back(other[i]);
          }
      }

      vector operator=(vector<T> &other) {
          if(v != &other) {
              v = other.v;

              if(v != NULL) {
                  delete []v;
              }
              for(int i = 0; i < s; i++) {
                  v.push_back(other[i]);
              }
          }
      }

      ~vector(){
	     delete [] v;
      }
	  
      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i = 0; i < s - 1; i++)
	        temp[i] = v[i];

	     delete [] v;
	     v = temp;
	     v[s-1] = ele;
      }

      T operator[](int a) {
          return v[a];
      }

      T at(int a) {
          if(a >= s) {
            throw std::out_of_range("out of my vector bounds");
          }
          return v[a];
      }

};