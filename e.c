int    tetricount(char *str)
{
    int i;
    int hashcount;

    hashcount = 0;
    i = 0;
    while (i < 19) 
    {
        if (str[i] && str[i] != '\n' && str[i] != '#' && str[i] != '.')
            return (0);
        if (str[i] == '\n' && !(str[i] == 4) && !(str[i] == 9) && !(str[i] == 14) && !(str[i] == 19))
            return (0);
        if (str[i] == '#')
            hashcount++;
        i++;
    }
    if (!str[i] || str[i]!= '\n')
        return (0);
    return (hashcount);
}

int    next_to_counter(char *str)
{
    int i;
    int hashcount;

    i = 0;
    hashcount = 0;
    while (i < 19)
    {
        if (str[i] == '#')
        {
            if (i + 1 <= 18 && str[i + 1] == '#')
                hashcount++;
            if (i - 1 >= 0 && str[i - 1] == '#')
                hashcount++;
            if (i + 5 <= 18 && str[i + 5] == '#')
                hashcount++;
            if (i - 5 >= 0 && str[i - 5] == '#')
                hashcount++;
        }
        i++;
    }
    return (hashcount);
}

int validator(char *str, int size)
{
    int i;

    i = 0;
    while (i <= size)
    {
        if (hashcount(str + i) != 4)
            return (0);
        if (next_to_counter(str + 1) != 6 && next_to_counter(str + i) != 8)
            return (0);
        i += 21;
    }
    return (1);
}