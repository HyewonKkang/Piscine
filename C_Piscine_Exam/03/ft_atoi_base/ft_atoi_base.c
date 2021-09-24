int is_space(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int isvalid(int c, int base)
{
    char digits[17] = "0123456789abcde";
    char digits2[17] = "0123456789ABCDE";

    while (base--)
    {
        if (digits[base] == c || digits2[base] == c)
            return (1);
    }
    return (0);
}

int value_of(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'z')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 10);
    return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
    int result;
    int negative;

    result = 0;
    negative = 1;
    while (is_space(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            negative = -1;
    }
    while (isvalid(*str, str_base))
    {
        result = result * str_base + value_of(*str);
        str++;
    }
    return (negative * result);
}
