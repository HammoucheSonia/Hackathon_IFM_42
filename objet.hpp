class produit
{
    std :: string marque;
    magasin s_magasin;
    int taille;
    int nb_restant;
    std :: string couleur;
    std :: string type;
    std :: string genre;
}; 

class marque
{
    int nb_magasins;
    std :: string entreprise;
    std :: string pays;
    int nb_stock_total;
}

class magasin
{
    std :: string marque; 
    int code_postale;
    std :: string pays;
};