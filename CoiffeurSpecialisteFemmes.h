#ifndef COIFFEUR_SPECIALISTE_FEMMES_H
#define COIFFEUR_SPECIALISTE_FEMMES_H

#include "Coiffeur.h"

class CoiffeurSpecialisteFemmes : public Coiffeur {
 public:
  // Constructeurs
  CoiffeurSpecialisteFemmes();
  CoiffeurSpecialisteFemmes(std::string nom, std::string adresse,std::string pays,std::string ville, std::vector<CoupeDeCheveux*> coupesDeCheveux);

  // Redéfinition de la fonction virtuelle
  double tarifTotal() const override;
};

#endif  // COIFFEUR_SPECIALISTE_FEMMES_H
