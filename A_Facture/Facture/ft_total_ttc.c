#include "facture.h"

long ft_total_ttc (long net_ht, long tva) {
    return (net_ht + (ft_pourcentage(net_ht, tva)));
}
