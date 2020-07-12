#include <exception>

/**
A dynamic array will double in size every time the size reaches capacity.
An amortized analysis shows that adding an element is still O(1).
*/

template <typename T>

class DynamicArray {
  public:
    void resize(int n);
    void get(int i);
    void set(int i, T val);
    
  private:
    int size;
    int capacity;
    T values[];
};

// example usage
int main () {
  DynamicArray<int> z;
}
