#include "Coiffeur.h"

// Constructeurs et Destructeur
Coiffeur::Coiffeur() {}

Coiffeur::Coiffeur(std::string nom, std::string adresse, std::string pays, std::string ville)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->pays_ = pays;
  this->ville_ = ville;
}

Coiffeur::Coiffeur(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveux *> coupesDeCheveux)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->coupesDeCheveux_ = coupesDeCheveux;
  this->pays_ = pays;
  this->ville_ = ville;
}

Coiffeur::~Coiffeur()
{
}


// Accesseurs et mutateurs
std::string Coiffeur::getNom() const 
{
  return this->nom_;
}

void Coiffeur::setNom(std::string nom) 
{
  this->nom_ = nom;
}

std::string Coiffeur::getAdresse() const 
{
  return this->adresse_;
}

void Coiffeur::setAdresse(std::string adresse) 
{
  this->adresse_ = adresse;
}

std::string Coiffeur::getPays() const
{
  return this->pays_;
}

void Coiffeur::setPays(std::string pays)
{
  this->pays_ = pays;
}

std::string Coiffeur::getVille() const
{
  return this->ville_;
}

void Coiffeur::setVille(std::string ville)
{
  this->ville_ = ville;
}

std::vector<CoupeDeCheveux*> Coiffeur::getCoupesDeCheveux() const 
{
  return this->coupesDeCheveux_;
}

void Coiffeur::setCoupesDeCheveux(std::vector<CoupeDeCheveux*> coupesDeCheveux) 
{
  this->coupesDeCheveux_ = coupesDeCheveux;
}


