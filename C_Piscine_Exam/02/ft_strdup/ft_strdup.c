#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
    int i;
    int len;
    char* copy;

    i = 0;
    len = ft_strlen(src);
    copy = (char*)malloc(sizeof(char) * len + 1);
    // while (*src)
    // {
    //     len++;
    //     src++;
    // }
    while (src[i])
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
