#include "CoupeDeCheveux.h"

// Constructeurs et Destructeurs
CoupeDeCheveux::CoupeDeCheveux() {}

CoupeDeCheveux::CoupeDeCheveux(std::string longueur, std::string couleur, std::string forme)
{
  this->longueur_ = longueur;
  this->couleur_ = couleur;
  this->forme_ = forme;
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

std::string CoupeDeCheveux::getCouleur() const 
{
  return this->couleur_;
}

void CoupeDeCheveux::setCouleur(std::string couleur) 
{
  this->couleur_ = couleur;
}

std::string CoupeDeCheveux::getForme() const
{
  return this->forme_;
}

void CoupeDeCheveux::setForme(std::string forme) 
{
  this->forme_ = forme;
}


// Fonctions
double CoupeDeCheveux::tarif() const 
{
  return 0;
}

std::string CoupeDeCheveux::description() const 
{
  return forme_ + " " + couleur_ + " " + longueur_;
}


