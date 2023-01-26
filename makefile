CC = g++
CFLAGS = -Wall -Wextra -std=c++17

SOURCES = CoupeDeCheveux.cpp CoupeDeCheveuxHommes.cpp CoupeDeCheveuxFemmes.cpp Coiffeur.cpp CoiffeurSpecialisteHommes.cpp CoiffeurSpecialisteFemmes.cpp main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = coupe_de_cheveux

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
