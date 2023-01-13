#ifndef COUPE_DE_CHEVEUX_H
#define COUPE_DE_CHEVEUX_H

#include <string>

class CoupeDeCheveux {
 public:
  // Constructeurs
  CoupeDeCheveux();
  CoupeDeCheveux(std::string longueur, std::string couleur, std::string forme);

  // Destructeur
  ~CoupeDeCheveux();

  // Accesseurs et mutateurs pour les champs
  std::string getLongueur() const;
  void setLongueur(std::string longueur);
  std::string getCouleur() const;
  void setCouleur(std::string couleur);
  std::string getForme() const;
  void setForme(std::string forme);

  // Fonctions
  //descprition
  virtual std::string description() const = 0;

  //tarif
  virtual double tarif() const = 0;

 protected:
  // Champs privés de la classe
 
    std::string longueur_;
    std::string couleur_;
    std::string forme_;
};

#endif // COUPE_DE_CHEVEUX_H
