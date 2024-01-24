#include "../../include/miniRT.h"

double ft_atof(char *str)
{
    double number;
    int sign;
    double factor;

    number = 0.0;

    sign = 1;
    factor = 1.0;
    while (is_white_space(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
        {
            sign *= -1;
        }
        str++;
    }
    while (ft_isdigit(*str))
    {
        number = number * 10 + (*str - '0');
        str++;
    }
    if (*str == '.')
    {
        str++;
        while (ft_isdigit(*str))
        {
            factor /= 10.0;
            number = number + (*str - '0') * factor;
            str++;
        }
    }
    return (number * sign);
}