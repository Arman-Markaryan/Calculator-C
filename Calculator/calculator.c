#include <stdio.h>
#include <stdlib.h> 

int main() {
    int operation;
    int *numbers;
    int numInputs, result;

    printf("Welcome to Calc!\n");
    printf("Choose the operation:\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Division\n");
    printf("4) Multiplication\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &operation);

    if (operation < 1 || operation > 4) {
        printf("Invalid choice\n");
        return 1;
    }

    switch(operation) {
        case 1:
            printf("You have chosen Addition\n");
            break;

        case 2:
            printf("You have chosen Subtraction\n");
            break;

        case 3:
            printf("You have chosen Division\n");
            break;

        case 4:
            printf("You have chosen Multiplication\n");
            break;
    }

    printf("Enter the number of values you want to %s: ", 
           (operation == 1) ? "add" : (operation == 2) ? "subtract" : (operation == 3) ? "divide" : "multiply");
    scanf("%d", &numInputs);

    numbers = (int *)malloc(numInputs * sizeof(int));

    for (int i = 0; i < numInputs; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    switch(operation) {
        case 1:
            result = 0;
            for (int i = 0; i < numInputs; i++) {
                result += numbers[i];
            }
            printf("Result: ");
            for (int i = 0; i < numInputs - 1; i++) {
                printf("%d + ", numbers[i]);
            }
            printf("%d = %d\n", numbers[numInputs - 1], result);
            break;

        case 2:
            result = numbers[0];
            for (int i = 1; i < numInputs; i++) {
                result -= numbers[i];
            }
            printf("Result: ");
            printf("%d - ", numbers[0]);
            for (int i = 1; i < numInputs - 1; i++) {
                printf("%d - ", numbers[i]);
            }
            printf("%d = %d\n", numbers[numInputs - 1], result);
            break;

        case 3:
            result = numbers[0];
            for (int i = 1; i < numInputs; i++) {
                if (numbers[i] == 0) {
                    printf("Error: Division by zero\n");
                    return 1;
                }
                result /= numbers[i];
            }
            printf("Result: ");
            printf("%d / ", numbers[0]);
            for (int i = 1; i < numInputs - 1; i++) {
                printf("%d / ", numbers[i]);
            }
            printf("%d = %d\n", numbers[numInputs - 1], result);
            break;

        case 4:
            result = 1;
            for (int i = 0; i < numInputs; i++) {
                result *= numbers[i];
            }
            printf("Result: ");
            for (int i = 0; i < numInputs - 1; i++) {
                printf("%d * ", numbers[i]);
            }
            printf("%d = %d\n", numbers[numInputs - 1], result);
            break;
    }

    free(numbers);

    return 0;
}
