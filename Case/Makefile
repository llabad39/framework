CC=g++
CFLAGS= --std=c++11 -Wall
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC =main 2048 2048Plus Taquin Sokoban 
OBJECTS = Case.o Chiffre.o ChiffreBase2.o ChiffreBase3.o ChiffreNegBase2.o ChiffreTaquin.o  Caisse.o Vide.o Mur.o Plateau.o Jeu.o Jeu2048.o Jeu2048Plus.o JeuSokoban.o JeuTaquin.o Fonction.o

all: $(EXEC)

main :	$(OBJECTS)
	$(CC) $(CFLAGS) -o main Main.cpp $(OBJECTS)

2048 :	$(OBJECTS)
	$(CC) $(CFLAGS) 2048Frame.cpp -o 2048  $(SFMLFLAGS) $(OBJECTS)

Taquin :	$(OBJECTS)
	$(CC) $(CFLAGS) TaquinFrame.cpp -o Taquin $(SFMLFLAGS)  $(OBJECTS)

2048Plus :	$(OBJECTS)
	$(CC) $(CFLAGS) 2048PlusFrame.cpp -o 2048Plus $(SFMLFLAGS)  $(OBJECTS)

Sokoban : 	$(OBJECTS)
	$(CC) $(CFLAGS) SokobanFrame.cpp -o Sokoban $(SFMLFLAGS)  $(OBJECTS)


%.o: %.cpp 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f *~
proper:	
	rm -f $(EXEC)
