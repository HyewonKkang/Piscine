#include <unistd.h>

int ft_strlen(char* str)
{
    int cnt;

    cnt = 0;
    while(str[cnt])
        ++cnt;
    return (cnt);
}

int main(int argc, char* argv[])
{
    int cnt;
    int len;

    if (argc == 3)
    {
        cnt = 0;
        len = ft_strlen(argv[1]);
        while(*argv[2])
        {
        if (*argv[2]++ == argv[1][cnt])
            ++cnt;
        }
    if (cnt == len)
        write(1, argv[1], len);
    }
    write(1, "\n", 1);
    return (0);
}
