#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>


#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/Coiffeur.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoiffeurSpecialisteFemmes.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoiffeurSpecialisteHommes.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoupeDeCheveux.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoupeDeCheveuxFemmes.h"
#include "/home/portable014/Bureau/neelp_1/MAIN_4_PC/Info/CoupeDuMonde/CoupeDeCheveuxHommes.h"

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

TEST_CASE("3 : Coupe De Cheveux Femmes")
{
    CoupeDeCheveuxFemmes coupe1("court", "afro",20,0);
    REQUIRE(coupe1.CoupeDeCheveux::getLongueur() == "court");
    REQUIRE(coupe1.CoupeDeCheveux::getForme() == "afro");
    REQUIRE(coupe1.CoupeDeCheveuxFemmes::getMeches() == 0);
    REQUIRE(coupe1.CoupeDeCheveuxFemmes::getTarif() == 20);

    coupe1.setMeches(1);
    REQUIRE(coupe1.CoupeDeCheveuxFemmes::getMeches() == 1);
    REQUIRE(coupe1.CoupeDeCheveuxFemmes::getTarif() == 30);
}

TEST_CASE("4 : Coupe De Cheveux Hommes")
{
    CoupeDeCheveuxHommes coupe2("court","degrade",15,1);
    REQUIRE(coupe2.CoupeDeCheveux::getLongueur() == "court");
    REQUIRE(coupe2.CoupeDeCheveux::getForme() == "degrade");
    REQUIRE(coupe2.CoupeDeCheveuxHommes::getTarif() == 20);
    REQUIRE(coupe2.CoupeDeCheveuxHommes::getBarbe() == 1);

    coupe2.setBarbe(0);
    REQUIRE(coupe2.CoupeDeCheveuxHommes::getTarif() == 15);
    REQUIRE(coupe2.CoupeDeCheveuxHommes::getBarbe() == 0);
}