#include <stdio.h>

int main() {
    char operation;
    int num1, num2, result;

    printf("Welcome to Calc!\n");
    printf("Choose the operation:\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Division\n");
    printf("4) Multiplication\n");

    printf("Enter your choice (1-4): ");
    scanf(" %c", &operation);

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    switch(operation) {
        case '1':
            result = num1 + num2;
            printf("Result: %d + %d = %d\n", num1, num2, result);
            break;

        case '2':
            result = num1 - num2;
            printf("Result: %d - %d = %d\n", num1, num2, result);
            break;

        case '3':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %d / %d = %d\n", num1, num2, result);
            } else {
                printf("Error: Division by zero\n");
            }
            break;

        case '4':
            result = num1 * num2;
            printf("Result: %d * %d = %d\n", num1, num2, result);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
