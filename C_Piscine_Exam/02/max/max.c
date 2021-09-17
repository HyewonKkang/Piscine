int max(int* tab, unsigned int len)
{
     int largest;
    unsigned int i;

    i = 1;
    if (len == 0)
        return (0);
    largest = tab[0];
    while (i < len)
    {
        if (largest < tab[i])
            largest = tab[i];
        i++;
    }
    return (largest);
}
