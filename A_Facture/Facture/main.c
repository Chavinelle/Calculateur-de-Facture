#include <unistd.h>
#include "facture.h"


int conversion (char *str, long *nombre_final) {
int i = 0;
long nombre = 0;

    if (!ft_is_number(str))
        return (0);
    while (ft_is_digit(str[i])) {
        nombre = nombre * 10 + (str[i] - '0');
        if (nombre > 1000000000)
            return (0);
        i++;
    }
    *nombre_final = nombre;
    return (1);
}

    int compteur (char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
    }

    static void affichage (char *str) {
    write(1, str, compteur (str));
    }

    static int affichage_erreur(char *str) {
    write(2, str, compteur (str));
    write(2, "\n", 1);
    return (1);
    }

    void affichage_nombre (long nombre) {
        char c;
    if (nombre >= 10) {
        affichage_nombre(nombre/10);
    }
    c = '0' + (nombre%10);
    write(1, &c, 1);
    }

    void affichage_devise (char *str, long montant) {
    affichage(str);
    affichage_nombre(montant);
    affichage(" FCFA\n");
    }
int main(int argc, char **argv)
{
    long prix, qte, tva, t_remise;
    long total_ht;
    long net_ht;
    long total_ttc;
    long montant_tva;
    long montant_remise;
    int i;

    if (argc != 5)
            return (affichage_erreur("Erreur : Entrez ./facture prix quantite tva remise"));
   i = 1;
    while (i<5){
        if (!ft_is_number(argv[i]))
            return (affichage_erreur("Erreur : Entrez uniquement des chiffes"));
        i++;
    }
    /*prix = conversion(argv[1], &prix);
    qte = conversion(argv[2], &qte);
    tva = conversion(argv[3], &tva);
    t_remise = conversion(argv[4], &t_remise);*/

    if (!conversion(argv[1], &prix) || !conversion(argv[2], &qte) || !conversion(argv[3], &tva) || !conversion(argv[4], &t_remise))
        return(affichage_erreur("Erreur : Entrez des nombres uniquement (max 1.000.000.000)"));
    if (qte > 1000000)
         return(affichage_erreur("Erreur : quantite max 1.000.000"));
    if ((!ft_is_percentage(tva)) || !ft_is_percentage(t_remise))
         return(affichage_erreur("Erreur : un taux doit être compris entre 0 et 100."));

    total_ht = ft_total_ht(prix, qte);
    net_ht = ft_net_commercial(total_ht, t_remise);
    montant_remise = total_ht - net_ht;
    total_ttc = ft_total_ttc(net_ht, tva);
    montant_tva = total_ttc - net_ht;

    affichage_devise("Total HT   : ", total_ht);
    affichage_devise("Remise     : ", montant_remise);
    affichage_devise("Net HT     : ", net_ht);
    affichage_devise("TVA        : ", montant_tva);
    affichage_devise("Total TTC  : ", total_ttc);

    return 0;
}
