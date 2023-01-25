#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>
// #include "CoupeDeCheveux.h"
// #include "CoupeDeCheveuxHommes.h"
// #include "CoupeDeCheveuxFemmes.h"
// #include "Coiffeur.h"
// #include "CoiffeurSpecialisteHommes.h"
// #include "CoiffeurSpecialisteFemmes.h"

#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/Coiffeur.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoiffeurSpecialisteFemmes.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoiffeurSpecialisteHommes.h"
TEST_CASE("1 : Coiffeur Spécialiste Femme")
{
    CoiffeurSpecialisteFemmes coiffeur("Pauline","Taillou","France","Ecotay");
    REQUIRE(coiffeur.Coiffeur::getNom() == "Pauline");
    REQUIRE(coiffeur.Coiffeur::getAdresse() == "Taillou");
    REQUIRE(coiffeur.Coiffeur::getPays() == "France");
    REQUIRE(coiffeur.Coiffeur::getVille() == "Ecotay");
    
}

TEST_CASE("2 : Coiffeur Spécialiste Homme")
{
    CoiffeurSpecialisteHommes coiffeur1("Samson","AbbePierre","France","Gretz");
    REQUIRE(coiffeur1.Coiffeur::getNom() == "Samson");
    REQUIRE(coiffeur1.Coiffeur::getAdresse() == "AbbePierre");
    REQUIRE(coiffeur1.Coiffeur::getPays() == "France");
    REQUIRE(coiffeur1.Coiffeur::getVille() == "Gretz");
}

//TEST_CASE("3 : ")