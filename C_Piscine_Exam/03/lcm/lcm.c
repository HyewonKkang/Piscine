unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int i;
    unsigned int gcd;

    i = a;
    while (i > 0)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break ;
        }
        i--;
    }
    return (a * b / i);
}
