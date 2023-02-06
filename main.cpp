#include <iostream>

#include "dynamicArray.hpp"

int main() {
    DynamicArray test;

    int option = 0, value = 0, index = 0;
    while (true) {
        printf("1 - Add to the end of the array\n");
        printf("2 - Remove from the end of the array\n");
        printf("3 - Add to a position in the array\n");
        printf("4 - Remove from a position in the array\n");
        printf("5 - Display the array\n");
        printf("6 - Get size of the array\n");
        printf("7 - Get an element from the array\n");
        printf("8 - Find the index of an element\n");
        printf("9 - Sort the array\n");
        printf("10 - Change the value of an element\n");
        printf("0 - Quit\n\n> ");
        scanf("%d", &option);
        system("cls");

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
                test.pop();
                break;
            }
            case 3: {
                printf("Enter a value:\n> ");
                scanf("%d", &value);
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.push(value, index);
                break;
            }
            case 4: {
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.pop(index);
                break;
            }
            case 5: {
                test.display();
                printf("\n");
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
                printf("Index of %d is: %d\n", value, test.indexOf(value));
                break;
            }
            case 9: {
                test.sort(0, test.getSize() - 1);
                printf("Array sorted\n");
                break;
            }
            case 10: {
                printf("Enter the new value:\n> ");
                scanf("%d", &value);
                printf("Enter an index:\n> ");
                scanf("%d", &index);
                test.change(value, index);
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