#ifndef COUPE_DE_CHEVEUX_H
#define COUPE_DE_CHEVEUX_H

#include <string>

class CoupeDeCheveux {
 public:
  // Constructeurs
  CoupeDeCheveux();
  CoupeDeCheveux(std::string longueur, std::string couleur, std::string forme,double tarif);

  // Destructeur
  ~CoupeDeCheveux();

  // Accesseurs et mutateurs pour les champs
  std::string getLongueur() const;
  void setLongueur(std::string longueur);
  std::string getCouleur() const;
  void setCouleur(std::string couleur);
  std::string getForme() const;
  void setForme(std::string forme);
  virtual double getTarif() const = 0;
  void setTarif(double tarif);

  // Fonctions
  virtual std::string description() const = 0;

 protected:
  // Champs privés de la classe
 
    std::string longueur_;
    std::string couleur_;
    std::string forme_;
    double tarif_;
};

#endif // COUPE_DE_CHEVEUX_H
