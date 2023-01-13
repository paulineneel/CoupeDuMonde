#ifndef COUPE_DE_CHEVEUX_HOMMES_H
#define COUPE_DE_CHEVEUX_HOMMES_H

#include "CoupeDeCheveux.h"

class CoupeDeCheveuxHommes : public CoupeDeCheveux {
 public:
  // Constructeurs
  CoupeDeCheveuxHommes();
  CoupeDeCheveuxHommes(std::string longueur, std::string couleur, std::string forme, bool barbe);

  // Accesseur et mutateur pour le champ barbe_
  bool getBarbe() const;
  void setBarbe(bool barbe);

  // Redéfinition des fonctions virtuelles
  std::string description() const override;
  double tarif() const override;

 private:
 
  bool barbe_;
};

#endif  // COUPE_DE_CHEVEUX_HOMMES_H
