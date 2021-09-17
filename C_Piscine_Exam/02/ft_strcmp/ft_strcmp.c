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

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (*s1)
    {
        if (*s1 > *s2)
            return (1);
        else if (*s1 < *s2)
            return (-1);
        s1++;
        s2++;
    }
    if (ft_strlen(s1) > ft_strlen(s2))
        return (1);
    else if (ft_strlen(s1) < ft_strlen(s2))
        return (-1);
    return (0);
}
