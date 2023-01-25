#include "CoupeDeCheveux.h"

// Constructeurs et Destructeurs
CoupeDeCheveux::CoupeDeCheveux() {}

CoupeDeCheveux::CoupeDeCheveux(std::string longueur, std::string forme,double tarif)
{
  this->longueur_ = longueur;
  this->forme_ = forme;
  this->tarif_ = tarif;
}

CoupeDeCheveux::~CoupeDeCheveux()
{
}


// Accesseurs et mutateurs
std::string CoupeDeCheveux::getLongueur() const 
{
  return this->longueur_;
}

void CoupeDeCheveux::setLongueur(std::string longueur) 
{
  this->longueur_ = longueur;
}

std::string CoupeDeCheveux::getForme() const
{
  return this->forme_;
}

void CoupeDeCheveux::setForme(std::string forme) 
{
  this->forme_ = forme;
}

double CoupeDeCheveux::getTarif() const
{
  return this->tarif_;
}

void CoupeDeCheveux::setTarif(double tarif)
{
  this->tarif_ = tarif;
}

// Fonctions

std::string CoupeDeCheveux::description() const 
{
  return forme_ + " " + longueur_;
}


