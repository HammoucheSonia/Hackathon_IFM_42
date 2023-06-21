#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

struct marque
{
    int nb_magasins;
    std :: string entreprise;
    std :: string pays;
    int nb_stock_total;
}s_marque;

struct magasin
{
    marque t_marque; 
    int code_postale;
    std :: string pays;
}s_magasin;

struct produit
{
    marque t_marque;
    magasin t_magasin;
    int taille;
    int nb_restant;
    std :: string couleur;
    std :: string type;
    std :: string genre;
}s_produit; 
