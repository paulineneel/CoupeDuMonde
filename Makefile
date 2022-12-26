CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard ../*.cpp)
OBJ= $(SRC:.cpp=.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cpp=.o)

Game : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^

%.o: %.cpp
	$(CC) $(CCFLAGS) -I../ -o $@ -c $< $(LIBS)

clean :
	rm -f $(OBJ_TEST) Game


