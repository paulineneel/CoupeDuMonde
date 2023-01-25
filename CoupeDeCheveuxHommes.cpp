#include "CoupeDeCheveuxHommes.h"

// Constructeurs
CoupeDeCheveuxHommes::CoupeDeCheveuxHommes() : CoupeDeCheveux()
{
  this->barbe_ = false;
}

CoupeDeCheveuxHommes::CoupeDeCheveuxHommes(std::string longueur, std::string forme,double tarif, bool barbe)
    : CoupeDeCheveux(longueur, forme,tarif)
{
  this->barbe_ = barbe;
}

CoupeDeCheveuxHommes::~CoupeDeCheveuxHommes()
{
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

double CoupeDeCheveuxHommes::getTarif() const {
  double tarif = CoupeDeCheveux::getTarif();
  if (barbe_) {
    tarif += 5;
  }
  return tarif;
}


