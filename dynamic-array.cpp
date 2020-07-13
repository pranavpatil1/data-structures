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
    int _size = 0;
    int _capacity = START_SIZE;
    T *_values;
  public:
    DynamicArray () {
      _values = new T[_capacity];
    }
    ~DynamicArray () {
      delete [] _values;
    }
    // change capacity
    void reserve(int n) {
      if (_capacity >= n) return;

      // double capacity until correct
      while (_capacity < n) _capacity *= 2;

      T *bigger = new T[_capacity];
      for (int i = 0; i < _size; i ++) {
        *(bigger+i) = *(_values+i);
      }
      delete [] _values;
      _values = bigger;
    }
    // change size
    void resize(int n) {
      if (_capacity < n) {
        while (_capacity < n) _capacity *= 2;
        T *bigger = new T[_capacity];
        for (int i = 0; i < _size; i ++) {
          *(bigger+i) = *(_values+i);
        }
        delete [] _values;
        _values = bigger;
      } else {
        int copyAmt = _size < n ? _size : n;
        // if n is greater than size
        for (int i = _size; i < n; i ++) {
          *(_values + i) = *(new T());
        }
      }
      _size = n;
    }
    T &get(int i) {
      if (i < _size) {
        return *(_values+i);
      } else {
        throw new std::out_of_range("Array index out of bounds");
      }
    };
    T &operator[] (int i) {
      // will not throw exception
      return *(_values+i);;
    }
    void set(int i, T val) {
      if (i < _size) {
        *(_values+i) = val; 
      } else {
        throw new std::out_of_range("Array index out of bounds");
      }
    };
    void push_back(T val) {
      if (_size == _capacity - 1) {
        _capacity *= 2;
        reserve(_capacity);
        *(_values+_size) = val;
        _size ++;
      } else {
        *(_values+_size) = val;
        _size ++;
      }
    }
    int capacity() {
      return _capacity;
    }
    int size() {
      return _size;
    }
    bool empty() {
      return _size == 0;
    }
};

// example usage
int main () {
  DynamicArray<int> z;
  std::cout << "Empty? " << (z.empty() ? "yes" : "no") << "\n";
  z.resize(5);
  std::cout << "first=" << z[0] << " last=" << z[z.size() - 1] << "\n";
  z.push_back(3);
  z.push_back(21);
  std::cout << "almost last=" << z[z.size() - 2] << " last=" << z[z.size() - 1] << "\n";
  z[0] = 19;
  std::cout << z[0] << "\n";
  z.reserve (100);
  std::cout << "capacity: " << z.capacity() << "\n";
  z.resize(4);
  std::cout << "first=" << z[0] << " size=" << z.size() << "\n";
  z.resize(200);
  std::cout << "first=" << z[0] << " size=" << z.size() << "\n";
}
