#include <stdio.h>
#include <math.h>

double userNumber() {
    double currentInput;
    printf("Entrer un nombre\n");
    scanf("%lf", &currentInput);
    fflush(stdin);

    return currentInput;
}

char userOperation() {
    char currentInput;
    printf("Entrer une operation\n");
    scanf("%c", &currentInput);
    fflush(stdin);

    return currentInput;
}

int main() {
    double firstNumber, secondNumber;
    char operation, isFirstOperation = 1;

    printf("Liste des opérations : (+)addition, (-)soustraction, (*)multiplication, (/)division, (^)puissance, (&)racine carré, (%)pourcentage et (c)effacer\n");

    while(1) {
        if (isFirstOperation == 1) {
            firstNumber = userNumber();
        }
        operation = userOperation();
        if (!(operation == '&' || operation == 'c')) {
            secondNumber = userNumber();
        }

        if(isFirstOperation == 1) isFirstOperation = 0;
        switch (operation) {
            case '+':
                firstNumber += secondNumber;
                break;
            case '-':
                firstNumber -= secondNumber;
                break;
            case '*':
                firstNumber *= secondNumber;
                break;
            case '/':
                firstNumber /= secondNumber;
                break;
            case '^':
                firstNumber = pow(firstNumber, secondNumber);
                break;
            case '&':
                firstNumber = sqrt(firstNumber);
                break;
            case '%':
                firstNumber = (secondNumber * firstNumber / 100);
                break;
            case 'c':
                isFirstOperation = 1;
                break;
            default:
                printf("Opératon invalide\n");
        }

        printf(" = %.2lf\n", firstNumber);
    }

    return 1;
}
