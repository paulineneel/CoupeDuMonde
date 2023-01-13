#include "CoupeDeCheveux.h"
#include "CoupeDeCheveuxHommes.h"
#include "CoupeDeCheveuxFemmes.h"
#include "Coiffeur.h"
#include "CoiffeurSpecialisteHommes.h"
#include "CoiffeurSpecialisteFemmes.h"

#include <iostream>
#include <vector>

int main() {
  // Création d'un coiffeur spécialisé dans les coupes de cheveux pour hommes
  std::vector<CoupeDeCheveux*> coupesDeCheveuxHommes {
      new CoupeDeCheveuxHommes("long", "noir", "ondulé", true),
      new CoupeDeCheveuxHommes("court", "marron", "lisse", false),
      new CoupeDeCheveuxHommes("mi-long", "blond", "bouclé", true)
  };
  CoiffeurSpecialisteHommes coiffeurHommes("John", "1234 Main Street", coupesDeCheveuxHommes);
  std::cout << "Coiffeur spécialisé dans les coupes de cheveux pour hommes" << std::endl;
  std::cout << "- Nom: " << coiffeurHommes.getNom() << std::endl;
  std::cout << "- Adresse: " << coiffeurHommes.getAdresse() << std::endl;
  std::cout << "- Coupes de cheveux proposées:" << std::endl;
  for (auto coupeDeCheveux : coiffeurHommes.getCoupesDeCheveux()) {
    std::cout << "  - " << coupeDeCheveux->description() << " (" << coupeDeCheveux->tarif() << " euros)" << std::endl;
  }
  std::cout << "- Tarif total des coupes de cheveux proposées: " << coiffeurHommes.tarifTotal() << " euros" << std::endl;
  std::cout << std::endl;

  // Création d'un coiffeur spécialisé dans les coupes de cheveux pour femmes
    std::vector<CoupeDeCheveux*> coupesDeCheveuxFemmes {
    new CoupeDeCheveuxFemmes("long", "roux", "ondulé", true),
    new CoupeDeCheveuxFemmes("court", "brun", "lisse", false),
    new CoupeDeCheveuxFemmes("mi-long", "blond", "bouclé", true)
    };
    CoiffeurSpecialisteFemmes coiffeurFemmes("Jane", "5678 Main Street", coupesDeCheveuxFemmes);
    std::cout << "Coiffeur spécialisé dans les coupes de cheveux pour femmes" << std::endl;
    std::cout << "- Nom: " << coiffeurFemmes.getNom() << std::endl;
    std::cout << "- Adresse: " << coiffeurFemmes.getAdresse() << std::endl;
    std::cout << "- Coupes de cheveux proposées:" << std::endl;
    for (auto coupeDeCheveux : coiffeurFemmes.getCoupesDeCheveux()) {
        std::cout << "  - " << coupeDeCheveux->description() << " (" << coupeDeCheveux->tarif() << " euros)" << std::endl;
    }
    std::cout << "- Tarif total des coupes de cheveux proposées: " << coiffeurFemmes.tarifTotal() << " euros" << std::endl;
    std::cout << std::endl;


  return 0;
}
