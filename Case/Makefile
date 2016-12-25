CC=g++
CFLAGS= --std=c++11 -Wall
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC =main 2048 2048Plus Taquin Sokoban 
OBJECTS = Case.o Chiffre.o ChiffreBase2.o ChiffreBase3.o ChiffreNegBase2.o ChiffreTaquin.o  Caisse.o Vide.o Mur.o Plateau.o Jeu.o Jeu2048.o Jeu2048Plus.o JeuSokoban.o JeuTaquin.o Fonction.o

all: $(EXEC)

main :	$(OBJECTS)
	$(CC) $(CFLAGS) $(SFMLFLAGS) -o main Main.cpp $(OBJECTS)

2048 :	$(OBJECTS)
	$(CC) $(CFLAGS) $(SFMLFLAGS) -o 2048 2048Frame.cpp $(OBJECTS)

Taquin :	$(OBJECTS)
	$(CC) $(CFLAGS) $(SFMLFLAGS) -o Taquin TaquinFrame.cpp $(OBJECTS)

2048Plus :	$(OBJECTS)
	$(CC) $(CFLAGS) $(SFMLFLAGS) -o 2048Plus 2048PlusFrame.cpp $(OBJECTS)

Sokoban : 	$(OBJECTS)
	$(CC) $(CFLAGS) $(SFMLFLAGS) -o Sokoban SokobanFrame.cpp $(OBJECTS)


%.o: %.cpp 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f *~
proper:	
	rm -f $(EXEC)
