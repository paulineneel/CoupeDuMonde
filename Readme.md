Exécution pour ouvrir fenetre : 

g++ -c main.cpp Game.cpp Quizz.cpp 
g++ main.o Quizz.o Game.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app