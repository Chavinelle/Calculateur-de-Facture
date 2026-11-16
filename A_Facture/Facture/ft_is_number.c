#include "facture.h"

int ft_is_number (char *str) {
    int i = 0;
    if (str == 0 || str[0] == '\0')
        return (0);
    while (ft_is_digit(str[i]))
        i++;
    if (str[i] != '\0')
        return (0);
    return (1);
}
