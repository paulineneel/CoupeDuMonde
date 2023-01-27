#include "Coiffeur.h"

// Constructeurs 
Coiffeur::Coiffeur() {}

// Constructeur avec paramètres nom, adresse, pays, ville
Coiffeur::Coiffeur(std::string nom, std::string adresse, std::string pays, std::string ville)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->pays_ = pays;
  this->ville_ = ville;
}

// Constructeur avec paramètres nom, adresse, pays, ville, coupesDeCheveux
Coiffeur::Coiffeur(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveux *> coupesDeCheveux)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->coupesDeCheveux_ = coupesDeCheveux;
  this->pays_ = pays;
  this->ville_ = ville;
}

// Destructeur
Coiffeur::~Coiffeur()
{
}


// Accesseur et mutateur pour le nom
std::string Coiffeur::getNom() const 
{
  return this->nom_;
}

void Coiffeur::setNom(std::string nom) 
{
  this->nom_ = nom;
}

// Accesseur et mutateur pour l'adresse
std::string Coiffeur::getAdresse() const 
{
  return this->adresse_;
}

void Coiffeur::setAdresse(std::string adresse) 
{
  this->adresse_ = adresse;
}

// Accesseur et mutateur pour le pays
std::string Coiffeur::getPays() const
{
  return this->pays_;
}

void Coiffeur::setPays(std::string pays)
{
  this->pays_ = pays;
}

// Accesseur et mutateur pour la ville

std::string Coiffeur::getVille() const
{
  return this->ville_;
}

void Coiffeur::setVille(std::string ville)
{
  this->ville_ = ville;
}



