#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1;
    int num2;
    char op;
    int result;

    if (argc == 4)
    {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[3]);
        op = argv[2][0];
        if (op == '+')
            result = num1 + num2;
        else if (op == '-')
            result = num1 - num2;
        else if (op == '*')
            result = num1 * num2;
        else if (op == '/')
            result = num1 / num2;
        else if (op == '%')
            result = num1 % num2;
        printf("%d", result);
    }
    write(1, "\n", 1);
}
