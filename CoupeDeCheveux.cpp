#include "CoupeDeCheveux.h"

// Constructeurs
CoupeDeCheveux::CoupeDeCheveux() {}

// Constructeur avec paramètres longueur, forme, tarif
CoupeDeCheveux::CoupeDeCheveux(std::string longueur, std::string forme,double tarif)
{
  this->longueur_ = longueur;
  this->forme_ = forme;
  this->tarif_ = tarif;
}

// Destructeur
CoupeDeCheveux::~CoupeDeCheveux()
{
}


// Accesseurs et mutateurs pour la longueur
std::string CoupeDeCheveux::getLongueur() const 
{
  return this->longueur_;
}

void CoupeDeCheveux::setLongueur(std::string longueur) 
{
  this->longueur_ = longueur;
}


// Accesseurs et mutateurs pour la forme
std::string CoupeDeCheveux::getForme() const
{
  return this->forme_;
}

void CoupeDeCheveux::setForme(std::string forme) 
{
  this->forme_ = forme;
}

// Accesseurs et mutateurs pour le tarif
double CoupeDeCheveux::getTarif() const
{
  return this->tarif_;
}

void CoupeDeCheveux::setTarif(double tarif)
{
  this->tarif_ = tarif;
}

// Méthode pour afficher la description d'une coupe de cheveux
std::string CoupeDeCheveux::description() const 
{
  return forme_ + " " + longueur_;
}


