#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray {
   private:
    int* arr = new int;
    int size = 0;
    void resize(int newSize = 0) {  // Used to reallocat memory for the array
        arr = (int*)realloc(arr, newSize);
        if (arr == nullptr) {
            std::cerr << "Memory allocation failed\n";
            exit(1);
        }
    }
    void swap(int* a, int* b) {  // Used by the sort method to swap to values
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    int partition(int start, int end) {  // Used by the sort method
        int pivot = arr[end];
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
    void quick(int start, int end) {
        if (start < end) {
            int pi = partition(start, end);
            quick(start, pi - 1);
            quick(pi + 1, end);
        }
    }

   public:
    void display() {  // Prints the elements of the array
        for (int i = 0; i < size; ++i) {
            printf("%d\n", arr[i]);
        }
    }
    int getSize() {  // Returns the current size of the array
        return size;
    }

    int get(int index) {  // Returns an element of the array by it's index
        if (index >= size || index < 0 || size == 0) {
            std::cerr << "Error\n";
            return 0;
        }
        return arr[index];
    }

    int indexOf(int value) {  // Returns the index of an element in the array, -1 if not found
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    void sort() {  // Sorts the array in ascending order
        quick(0, size - 1);
    }

    void push(int value) {  // Adds an element to the end of the array
        resize(size + 1);
        arr[size] = value;
        ++size;
    }
    void push(int value, int index) {  // Adds an element to a specific position in the array
        if (index > size || index < 0) {
            std::cerr << "Invalid index\n";
            return;
        }
        resize(++size);
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
    void pop(int index) {  // Removes the element at an index
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

    void change(int value, int index) {  // Change the value of an element in the array
        if (index >= size || index < 0 || size == 0) {
            std::cerr << "Error\n";
            return;
        }
        arr[index] = value;
    }
};

#endif