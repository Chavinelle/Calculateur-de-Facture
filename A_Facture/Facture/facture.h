#ifndef FACTURE_H
#define FACTURE_H

int ft_is_digit (char c);
int ft_is_number (char *str);
int ft_is_percentage (long n);
long ft_net_commercial (long total_brut, long remise);
long ft_pourcentage (long montant, long taux);
long ft_total_ht (long prix, long qte);
long ft_total_ttc (long net_ht, long tva);

#endif // FACTURE_H
