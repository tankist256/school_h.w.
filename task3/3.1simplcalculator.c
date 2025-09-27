#include <stdio.h>
#include <stdlib.h>

int a2i(char *number);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return 1;
    }

    int num1 = a2i(argv[1]);
    int num2 = a2i(argv[3]);
    char op = argv[2][0];
    int result;

    switch (op)
    {
    case '+':
        result = num1 + num2;
        printf("%d\n", result);
        break;
    case '-':
        result = num1 - num2;
        printf("%d\n", result);
        break;
    case '*':
        result = num1 * num2;
        printf("%d\n", result);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Error: Division by zero\n");
            return 1;
        }
        result = num1 / num2;
        printf("%d\n", result);
        break;
    default:
        printf("Error: Unknown operator '%c'\n", op);
        return 1;
    }

    return 0;
}

int a2i(char *number)
{
    int result = 0;
    int i = 0;
    int sign = 1;

    if (number[0] == '-')
    {
        sign = -1;
        i++;
    }

    while (number[i] != '\0')
    {
        if (number[i] < '0' || number[i] > '9')
        {
            break;
        }
        result = result * 10 + (number[i] - '0');
        i++;
    }

    return sign * result;
}