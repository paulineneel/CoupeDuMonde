#include "CoupeDeCheveuxHommes.h"

// Constructeurs
CoupeDeCheveuxHommes::CoupeDeCheveuxHommes() : CoupeDeCheveux()
{
  this->barbe_ = false;
}

CoupeDeCheveuxHommes::CoupeDeCheveuxHommes(std::string longueur, std::string couleur, std::string forme, bool barbe)
    : CoupeDeCheveux(longueur, couleur, forme)
{
  this->barbe_ = barbe;
}


// Accesseur et mutateur
bool CoupeDeCheveuxHommes::getBarbe() const {
  return this->barbe_;
}

void CoupeDeCheveuxHommes::setBarbe(bool barbe) {
  this->barbe_ = barbe;
}


// Fonctions
std::string CoupeDeCheveuxHommes::description() const {
  std::string description = CoupeDeCheveux::description();
  if (barbe_) {
    description += " avec barbe";
  } else {
    description += " sans barbe";
  }
  return description;
}

double CoupeDeCheveuxHommes::tarif() const {
  double tarif = CoupeDeCheveux::tarif();
  if (barbe_) {
    tarif += 5;
  }
  return tarif;
}

