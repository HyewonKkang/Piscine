int ft_strlen(char *s)
{
    int cnt;

    cnt = 0;
    while(*s)
    {
        cnt++;
        s++;
    }
    return (cnt);
}

char *ft_strrev(char *str)
{
    int i;
    int j;
    char tmp;

    i = 0;
    j = ft_strlen(str) - 1;
    while(i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}
