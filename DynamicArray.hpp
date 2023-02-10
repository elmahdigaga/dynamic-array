#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

template <class T>
class DynamicArray {
   private:
    T* arr;
    int size;

    void resize(int newSize = 0) {  // Used to reallocat memory for the array
        T* newArr = new T[newSize];
        if (newSize > size) {
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
        } else {
            for (int i = 0; i < newSize; ++i) {
                newArr[i] = arr[i];
            }
        }
        delete[] arr;
        arr = newArr;
    }

    void swap(T* a, T* b) {  // Used by the sort method to swap to values
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }

    int partition(int start, int end) {  // Used by the QuickSort method
        T pivot = arr[end];
        int i = (start - 1);
        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[end]);
        return (i + 1);
    }

    void quick(int start, int end) {  // the QuickSort algorithm
        if (start < end) {
            int pi = partition(start, end);
            quick(start, pi - 1);
            quick(pi + 1, end);
        }
    }

   public:
    DynamicArray() {  // Constructor
        arr = new T;
        size = 0;
    }

    ~DynamicArray() {  // Destructor
        delete[] arr;
    }

    void print() {  // Prints the elements of the array
        printf("[");
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i];
            if (i < size - 1) printf(", ");
        }
        printf("]\n");
    }

    int getSize() {  // Returns the current size of the array
        return size;
    }

    T get(int index) {  // Returns an element of the array by it's index
        if (index >= size || index < 0 || size == 0) {
            std::cerr << "Error\n";
            return 0;
        }
        return arr[index];
    }

    int find(T value) {  // Returns the index of the 1st occurrence of an element in the array, -1 if not found
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    void sort() {  // Sorts the array in ascending order
        quick(0, size - 1);
    }

    void push(T value) {  // Adds an element to the end of the array
        resize(size + 1);
        arr[size] = value;
        ++size;
    }

    void insert(T value, int index) {  // Adds an element to a specific position in the array
        if (index > size || index < 0) {
            std::cerr << "Invalid index\n";
            return;
        }
        resize(size + 1);
        ++size;
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
    }

    void pop() {  // Removes the last element of the array
        if (size == 0) return;
        resize(size - 1);
        --size;
    }

    void remove(int index) {  // Removes the element at an index
        if (index >= size || index < 0 || size == 0) {
            std::cerr << "Invalid index\n";
            return;
        }
        --size;
        for (int i = index; i < size; ++i) {
            arr[i] = arr[i + 1];
        }
        resize(size);
    }

    void change(T value, int index) {  // Change the value of an element in the array
        if (index >= size || index < 0 || size == 0) {
            std::cerr << "Error\n";
            return;
        }
        arr[index] = value;
    }

    void reverse() {
        for (int i = 0; i < size / 2; ++i) {
            swap(&arr[i], &arr[size - i - 1]);
        }
    }

    bool isEmpty() {
        return (size == 0);
    }

    DynamicArray operator+(DynamicArray const& obj) {
        DynamicArray<T> result;
        result.size = this->size + obj.size;
        result.resize(this->size + obj.size);

        int i = 0, j = 0;
        for (i = 0; i < this->size; ++i) {
            result.arr[i] = this->arr[i];
        }
        for (j = 0; j < obj.size; ++j) {
            result.arr[i] = obj.arr[j];
            ++i;
        }

        return result;
    }
};

#endif
