#include "objet.hpp"


std::string calculer_hash_produit(const produit& p) {
    std::string produit_str =
        std::to_string(p.t_marque.nb_magasins) +
        p.t_marque.entreprise +
        p.t_marque.pays +
        std::to_string(p.t_marque.nb_stock_total) +
        std::to_string(p.t_magasin.code_postale) +
        p.t_magasin.pays +
        std::to_string(p.taille) +
        std::to_string(p.nb_restant) +
        p.couleur +
        p.type +
        p.genre;
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)produit_str.c_str(), produit_str.length(), hash);
    
    std::string hash_produit;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        char hex[3];
        sprintf(hex, "%02x", hash[i]);
        hash_produit += hex;
    }
    
    return hash_produit;
}


int main()
{
    marque Dior;
    Dior.nb_magasins = 7;
    Dior.entreprise = "LVMH";
    Dior.pays = "France";
    Dior.nb_stock_total = 100;

    magasin Paris_5;
    Paris_5.t_marque = Dior;
    Paris_5.code_postale = 75005;
    Paris_5.pays = "France";

    produit pantalon;
    pantalon.t_marque = Dior;
    pantalon.t_magasin = Paris_5;
    pantalon.taille = 40;
    pantalon.couleur = "bleu";
    pantalon.type = "classique";
    pantalon.genre = "femme";

    
    std::string hash = calculer_hash_produit(pantalon);
    std::cout << "Identifiant unique du produit : " << hash << std::endl;
    
    return(0);
}