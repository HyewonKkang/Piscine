int ft_atoi(const char *str)
{
    int i;
    int negative;
    int result;

    i = 0;
    negative = 1;
    result = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
        else if (str[i] == '-')
            negative = -1;
        else
        {
            break;
        }
        i++;
    }
    return (result * negative);
}
