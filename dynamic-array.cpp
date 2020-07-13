#include <stdexcept>
#include <iostream>

/**
A dynamic array will double in size every time the size reaches capacity.
An amortized analysis shows that adding an element is still O(1).
*/

const int START_SIZE = 20;

template <typename T>
class DynamicArray {
  private:
    int size = 0;
    int capacity = START_SIZE;
    T *values;
  public:
    DynamicArray () {
      values = new T[capacity];
    }
    ~DynamicArray () {
      delete [] values;
    }
    void resize(int n) {
      // if shrinking, then only copy first n
      int copyAmt = size < n ? size : n;
      capacity = n;
      T *bigger = new T[capacity];
      for (int i = 0; i < size; i ++) {
        *(bigger+i) = *(values+i);
      }
      delete [] values;
      values = bigger;
    }
    T &get(int i) {
      if (i < size) {
        return *(values+i);
      } else {
        throw new std::out_of_range("Array index out of bounds");
      }
    };
    T &operator[] (int i) {
      return get(i);
    }
    void set(int i, T val) {
      if (i < size) {
        *(values+i) = val; 
      } else {
        throw new std::out_of_range("Array index out of bounds");
      }
    };
    void push_back(T val) {
      if (size == capacity) {
        capacity *= 2;
        resize(capacity);
        *(values+size) = val;
        size ++;
      } else {
        *(values+size) = val;
        size ++;
      }
    }
};

// example usage
int main () {
  DynamicArray<int> z;
  z.push_back(3);
  z.push_back(21);
  z[0] = 19;
  std::cout << z[0] << " " << z[1] << "\n";
}
