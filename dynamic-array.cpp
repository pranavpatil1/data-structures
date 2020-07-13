#include <stdexcept>

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
    T values[START_SIZE];
  public:
    DynamicArray() {
      //this->size = 0;
      //this->capacity = START_SIZE;
      //values = {};
    }
    void resize(int n);
    T &get(int i) {
      if (i < size) {
        return values[i];
      } else {
        throw new std::out_of_range("Array index out of bounds");
      }
    };
    T &operator[] (int i) {
      this.get(i);
    }
    void set(int i, T val) {
      if (i < size) {
        values[i] = val; 
      } else {
        throw new std::out_of_range("Array index out of bounds");
      }
    };
    void push_back(T val) {
      size ++;
      if (size == capacity) {
        capacity *= 2;
        T bigger[capacity];
        for (int i = 0; i < size - 1; i ++) {
          bigger[i] = this->values[i];
        }
        bigger[size - 1] = val;
        this->values = bigger;
      } else {
        this->values[size - 1] = val;
      }
    }
};

// example usage
int main () {
  DynamicArray<int> z;
}
