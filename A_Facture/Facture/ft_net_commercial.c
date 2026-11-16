#include "facture.h"

long ft_net_commercial (long total_brut, long remise) {
    return (total_brut - ft_pourcentage(total_brut, remise));
}
