#include <unistd.h>

int isInclude(char* arr, char c, int idx)
{
    int i;

    i = 0;
    while (i < idx)
    {
        if (arr[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int isInclude2(char* arr1, char* arr2, char c, int idx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (arr1[i])
    {
        if (arr1[i] == c)
            return (1);
        i++;
    }
    while (j < idx)
    {
        if (arr2[j] == c)
            return (1);
        j++;
    }
    return (0);
}

int main(int argc, char* argv[])
{
    char* arr;
    int i;

    i = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (isInclude(argv[1], argv[1][i], i) == 0)
            {
                write(1, &argv[1][i], 1);
            }
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            if (!isInclude2(argv[1], argv[2], argv[2][i], i))
            {
                write(1, &argv[2][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);

    return (0);
}
