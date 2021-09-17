unsigned char reverse_bits(unsigned char octet)
{
    int i;
    unsigned char result;

    i = 128;
    result = 0;
    while (i > 0)
    {
        result = result * 2 + (octet % 2);
        octet /= 2;
        i /= 2;
    }
    return result;
}
