#include "CoupeDeCheveux.h"
#include "CoupeDeCheveuxHommes.h"
#include "CoupeDeCheveuxFemmes.h"
#include "Coiffeur.h"
#include "CoiffeurSpecialisteHommes.h"
#include "CoiffeurSpecialisteFemmes.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

std::string readFileIntoString(const std::string& path) {
    auto ss = std::ostringstream{};
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

std::vector<std::vector<std::string>> transformCSVtoString(std::string filename,char del) 
{
  std::vector<std::vector<std::string>> csv_contents;
  std::string file_contents;
  file_contents = readFileIntoString(filename);

  std::istringstream sstream(file_contents);
  std::vector<std::string> items;
  std::string record;

  int counter = 0;
  while (std::getline(sstream, record)) 
  {
    std::istringstream line(record);
    while (std::getline(line, record, del)) 
    {
      items.push_back(record);
      //std::cout << items[counter] << " " << std::endl;
      counter += 1;
    }
    //std::cout << "\n" << std::endl;
    csv_contents.push_back(items);
    items.clear();
    counter = 0;
  }
  return csv_contents;
}

int main() {
  // Lecture fichiers csv
  std::string filename1("liste_coiffeurs.csv");
  std::string filename2("liste_coupes_de_cheveux.csv");
  char delimiter = ';';

  std::vector<std::vector<std::string>> csv_coiffeurs = transformCSVtoString(filename1,delimiter);
  std::vector<std::vector<std::string>> csv_coiffures = transformCSVtoString(filename2,delimiter);

  std::vector<Coiffeur*> coiffeurHommes;
  std::vector<Coiffeur*> coiffeurFemmes;
  
  // Création coupes de cheveux
  int ind_csv_coiffure = 1;

  int nbTotalCoiffure = csv_coiffures.size();
  int nbCoiffeur = csv_coiffeurs.size();


  for(int i = 1; i< nbCoiffeur;i++ ) //on commence à 1 car 1ere ligne = nom des attributs
  {     // créer des coiffeurs selon leur specialite
    
    if(csv_coiffeurs[i][4] == "F")
    {
      coiffeurFemmes.push_back(new CoiffeurSpecialisteFemmes(csv_coiffeurs[i][0],csv_coiffeurs[i][1],csv_coiffeurs[i][2],
      csv_coiffeurs[i][3]));
    }
    else
    {
      coiffeurHommes.push_back(new CoiffeurSpecialisteHommes(csv_coiffeurs[i][0],csv_coiffeurs[i][1],csv_coiffeurs[i][2],
      csv_coiffeurs[i][3]));
    }

  }


  std::string nom = csv_coiffures[1][0]; // nom 1er du coiffeur

  while(ind_csv_coiffure < nbTotalCoiffure) //on commence à 1 car 1ere ligne = nom des attributs
  {

    if (csv_coiffures[ind_csv_coiffure][4] == "F") //coiffeurSpeFemmes
    {
      std::vector<CoupeDeCheveux*> coupesDeCheveuxFemmes;
    
      while(ind_csv_coiffure < nbTotalCoiffure && csv_coiffures[ind_csv_coiffure][0] == nom) //ajoute toutes les coupes d'un coiffeur
      {
        coupesDeCheveuxFemmes.push_back(new CoupeDeCheveuxFemmes(
            csv_coiffures[ind_csv_coiffure][1],csv_coiffures[ind_csv_coiffure][2],
            csv_coiffures[ind_csv_coiffure][3],std::stof(csv_coiffures[ind_csv_coiffure][5]),false));

        ind_csv_coiffure++;
      }
    
      //On ajoute les coiffures au coiffeur correspondant
      for(auto coif : coiffeurFemmes)
      {
        if (coif->getNom() == nom)
        {
          coif->setCoupesDeCheveux(coupesDeCheveuxFemmes);
        }
      }
    }
    
    else
    {
      std::vector<CoupeDeCheveux*> coupesDeCheveuxHommes;
    
      while(ind_csv_coiffure < nbTotalCoiffure && csv_coiffures[ind_csv_coiffure][0] == nom) //ajoute toutes les coupes d'un coiffeur
      {
        coupesDeCheveuxHommes.push_back(new CoupeDeCheveuxFemmes(
            csv_coiffures[ind_csv_coiffure][1],csv_coiffures[ind_csv_coiffure][2],
            csv_coiffures[ind_csv_coiffure][3],std::stof(csv_coiffures[ind_csv_coiffure][5]),false));

        ind_csv_coiffure++;
      }

      //On ajoute les coiffures au coiffeur correspondant
      for(auto coif : coiffeurHommes)
      {
        if (coif->getNom() == nom)
        {
          coif->setCoupesDeCheveux(coupesDeCheveuxHommes);
        }
      }
    }

    if(ind_csv_coiffure<nbTotalCoiffure)
      nom = csv_coiffures[ind_csv_coiffure][0];
  }

    
  for(auto coiffeurF : coiffeurFemmes)
  {
    std::cout << "Coiffeur spécialisé dans les coupes de cheveux pour femmes" << std::endl;
    std::cout << "- Nom: " << coiffeurF->getNom() << std::endl;
    std::cout << "- Adresse: " << coiffeurF->getPays() << std::endl;
    std::cout << "- Adresse: " << coiffeurF->getVille() << std::endl;
    std::cout << "- Adresse: " << coiffeurF->getAdresse() << std::endl;
    std::cout << "- Coupes de cheveux proposées:" << std::endl;
    for (auto coupeDeCheveux : coiffeurF->getCoupesDeCheveux()) 
    {
        std::cout << "  - " << coupeDeCheveux->description() << " (" << coupeDeCheveux->getTarif() << " euros)" << std::endl;
        //std::cout << "- Tarif total de la coupe: " << coiffeurF->tarifTotal(true,false) << " euros" << std::endl;
    }
      
    std::cout << std::endl;
  }

  
  for(auto coiffeurH : coiffeurHommes)
  {
    std::cout << "Coiffeur spécialisé dans les coupes de cheveux pour hommes" << std::endl;
    std::cout << "- Nom: " << coiffeurH->getNom() << std::endl;
    std::cout << "- Adresse: " << coiffeurH->getPays() << std::endl;
    std::cout << "- Adresse: " << coiffeurH->getVille() << std::endl;
    std::cout << "- Adresse: " << coiffeurH->getAdresse() << std::endl;
    std::cout << "- Coupes de cheveux proposées:" << std::endl;
    for (auto coupeDeCheveux : coiffeurH->getCoupesDeCheveux()) {
      std::cout << "  - " << coupeDeCheveux->description() << " (" << coupeDeCheveux->getTarif() << " euros)" << std::endl;
    }
    std::cout << "- Tarif total des coupes de cheveux proposées: " << coiffeurH->tarifTotal(false,false) << " euros" << std::endl;
    std::cout << std::endl;
  }

 
  return 0;
}