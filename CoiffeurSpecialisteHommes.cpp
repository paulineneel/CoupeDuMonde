#include "CoiffeurSpecialisteHommes.h"

// Constructeurs
CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes() : Coiffeur() {}

CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveux *> coupesDeCheveux)
  : Coiffeur(nom, adresse, pays, ville, coupesDeCheveux)
{
}


// Fonctions
double CoiffeurSpecialisteHommes::tarifTotal() const {
  double tarifTotal = 0;
  for (auto coupeDeCheveux : coupesDeCheveux_) {
    tarifTotal += coupeDeCheveux->tarif();
  }
  return tarifTotal;
}
