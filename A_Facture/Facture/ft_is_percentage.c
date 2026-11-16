#include "facture.h"

int ft_is_percentage (long n) {
    if (n >= 0 && n <= 100)
        return (1);
    return 0;
}
