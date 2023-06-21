#include "objet.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string calculer_hash_produit(const s_produit& produit) {
    // Concaténer les attributs pertinents du produit en une chaîne de caractères
    std::stringstream ss;
    ss << produit.t_marque.nb_magasins
       << produit.t_marque.entreprise
       << produit.t_marque.pays
       << produit.t_marque.nb_stock_total
       << produit.t_magasin.code_postale
       << produit.t_magasin.pays
       << produit.taille
       << produit.nb_restant
       << produit.couleur
       << produit.type
       << produit.genre;
    std::string produit_str = ss.str();
    
    // Calculer le hash SHA-256
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(produit_str.c_str()), produit_str.length(), hash);
    
    // Convertir le hash en une chaîne hexadécimale
    std::stringstream hash_ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hash_ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    
    return hash_ss.str();
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
    
    return(0);
}