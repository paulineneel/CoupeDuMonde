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
  
  // Création coupes de cheveux
  int ind_csv_coiffure = 1;
  int ind_csv_coiffeur = 0;
  std::string Nom = csv_coiffures[ind_csv_coiffure][0]; // nom 1er du coiffeur
  std::cout << Nom << "\n" << std::endl;

  if (csv_coiffures[ind_csv_coiffure][4] == "F") //coupe femme
  {
    std::vector<CoupeDeCheveux*> coupesDeCheveuxFemmes;
    while(ind_csv_coiffure <57) //ajoute toutes les coupes d'un coiffeur
    {
      if (csv_coiffures[ind_csv_coiffure][0] == Nom)
        coupesDeCheveuxFemmes.push_back(new CoupeDeCheveuxFemmes(
        csv_coiffures[ind_csv_coiffure][1],csv_coiffures[ind_csv_coiffure][2],
        csv_coiffures[ind_csv_coiffure][3],std::stof(csv_coiffures[ind_csv_coiffure][5]),false));

      ind_csv_coiffure++;
    } 

    for(int i =0;i<3;i++)//cherche l'indice du coiffeur dans le fichier csv coiffeur
    {
      if(csv_coiffeurs[i][0] == Nom){
        ind_csv_coiffeur=i;
      }
    }

    CoiffeurSpecialisteFemmes coiffeurFemmes( //créée le coiffeur
      csv_coiffeurs[ind_csv_coiffeur][0],csv_coiffeurs[ind_csv_coiffeur][1],csv_coiffeurs[ind_csv_coiffeur][2],
      csv_coiffeurs[ind_csv_coiffeur][3],coupesDeCheveuxFemmes);
    
    std::cout << "Coiffeur spécialisé dans les coupes de cheveux pour femmes" << std::endl;
    std::cout << "- Nom: " << coiffeurFemmes.getNom() << std::endl;
    std::cout << "- Adresse: " << coiffeurFemmes.getAdresse() << std::endl;
    std::cout << "- Coupes de cheveux proposées:" << std::endl;
    for (auto coupeDeCheveux : coiffeurFemmes.getCoupesDeCheveux()) 
    {
        std::cout << "  - " << coupeDeCheveux->description() << " (" << coupeDeCheveux->tarif() << " euros)" << std::endl;
    }
    std::cout << "- Tarif total des coupes de cheveux proposées: " << coiffeurFemmes.tarifTotal() << " euros" << std::endl;
    std::cout << std::endl;

  }

  else{ //coupe homme
    std::vector<CoupeDeCheveux*> coupesDeCheveuxHommes;
    while(csv_coiffures[ind_csv_coiffure][0] == Nom) //ajoute toutes les coupes d'un coiffeur
    {
      coupesDeCheveuxHommes.push_back(new CoupeDeCheveuxHommes(
        csv_coiffures[ind_csv_coiffure][1],csv_coiffures[ind_csv_coiffure][2],
        csv_coiffures[ind_csv_coiffure][3],std::stof(csv_coiffures[ind_csv_coiffure][5]),false));

      ind_csv_coiffure++;
    } 

    while(csv_coiffeurs[ind_csv_coiffeur][0] != Nom && ind_csv_coiffeur<=3) //cherche l'indice du coiffeur dans le fichier csv coiffeur
    {
      ind_csv_coiffeur++;
    }

    CoiffeurSpecialisteHommes coiffeurHommes( //créée le coiffeur
      csv_coiffeurs[ind_csv_coiffeur][0],csv_coiffeurs[ind_csv_coiffeur][0],csv_coiffeurs[ind_csv_coiffeur][0],
      csv_coiffeurs[ind_csv_coiffeur][0],coupesDeCheveuxHommes);

    std::cout << "Coiffeur spécialisé dans les coupes de cheveux pour hommes" << std::endl;
    std::cout << "- Nom: " << coiffeurHommes.getNom() << std::endl;
    std::cout << "- Adresse: " << coiffeurHommes.getAdresse() << std::endl;
    std::cout << "- Coupes de cheveux proposées:" << std::endl;
    for (auto coupeDeCheveux : coiffeurHommes.getCoupesDeCheveux()) {
      std::cout << "  - " << coupeDeCheveux->description() << " (" << coupeDeCheveux->tarif() << " euros)" << std::endl;
    }
    std::cout << "- Tarif total des coupes de cheveux proposées: " << coiffeurHommes.tarifTotal() << " euros" << std::endl;
    std::cout << std::endl;

  }

 
  return 0;
}
