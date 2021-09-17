#include <unistd.h>

int main(int argc, char* argv[])
{
    int arr[128] = {0, };
    int i;

    i = 0;
    if (argc == 3)
    {
        while (argv[2][i])
        {
            if (arr[(int)argv[2][i]] == 0)
                arr[(int)argv[2][i]] += 1;
            i++;
        }
        i = 0;
        while (argv[1][i])
        {
            if (arr[(int)argv[1][i]] == 1)
            {
                write(1, &argv[1][i], 1);
                arr[(int)argv[1][i]] -= 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
