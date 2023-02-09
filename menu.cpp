#include <iostream>

#include "dynamicArray.hpp"

int main() {
    DynamicArray<int> test;

    int option = 0, index = 0;
    int value = 0;
    while (true) {
        printf("1 - Push an element\n");
        printf("2 - Insert an element to a position\n");
        printf("3 - Pop an element\n");
        printf("4 - Remove an element from a position\n");
        printf("5 - Change an element\n");
        printf("6 - Get size\n");
        printf("7 - Get an element by index\n");
        printf("8 - Find the index of an element\n");
        printf("9 - Sort the array\n");
        printf("10 - Reverse the array\n");
        printf("11 - Print the array\n");
        printf("0 - Quit\n\n> ");
        scanf("%d", &option);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        system("cls");
#else
        system("clear");
#endif

        switch (option) {
            case 0: {
                printf("Goodbye!\n");
                return 0;
            }
            case 1: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                test.push(value);
                break;
            }
            case 2: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.insert(value, index);
                break;
            }
            case 3: {
                test.pop();
                break;
            }
            case 4: {
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.remove(index);
                break;
            }
            case 5: {
                printf("Enter the new value:\n> ");
                scanf("%d", &value);
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.change(value, index);
                break;
            }
            case 6: {
                printf("Size: %d\n", test.getSize());
                break;
            }
            case 7: {
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                printf("Value: %d\n", test.get(index));
                break;
            }
            case 8: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                printf("Index of %d is: %d\n", value, test.find(value));
                break;
            }
            case 9: {
                test.sort();
                printf("Array sorted\n");
                break;
            }
            case 10: {
                test.reverse();
                printf("Array reversed\n");
                break;
            }
            case 11: {
                test.print();
                printf("\n");
                break;
            }

            default: {
                printf("Invalid input!\n");
                break;
            }
        }
    }

    return 0;
}