#include "CoiffeurSpecialisteFemmes.h"

// Constructeurs
CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes() : Coiffeur() {}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::vector<CoupeDeCheveux*> coupesDeCheveux)
    : Coiffeur(nom, adresse, coupesDeCheveux) {}


// Fonctions
double CoiffeurSpecialisteFemmes::tarifTotal() const {
  double tarifTotal = 0;
  for (auto coupeDeCheveux : coupesDeCheveux_) {
    tarifTotal += coupeDeCheveux->tarif();
  }
  return tarifTotal;
}
