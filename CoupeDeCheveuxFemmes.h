#ifndef COUPE_DE_CHEVEUX_FEMMES_H
#define COUPE_DE_CHEVEUX_FEMMES_H

#include "CoupeDeCheveux.h"

class CoupeDeCheveuxFemmes : public CoupeDeCheveux {
 public:
  // Constructeurs
  CoupeDeCheveuxFemmes();
  CoupeDeCheveuxFemmes(std::string longueur, std::string couleur, std::string forme,double tarif, bool meches);

  // Accesseur et mutateur pour le champ meches_
  bool getMeches() const;
  void setMeches(bool meches);

  // Redéfinition des fonctions virtuelles
  std::string description() const override;
  double tarif() const override;

 private:
 
  bool meches_;
};

#endif  // COUPE_DE_CHEVEUX_FEMMES_H
