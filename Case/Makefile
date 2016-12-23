CC=g++
CFLAGS= --std=c++11 -Wall
EXEC =main 
OBJECTS = Case.o ChiffreFus.o ChiffreBase2.o ChiffreBase3.o ChiffreNegBase2.o Chiffre.o  Caisse.o Vide.o Mur.o Plateau.o Jeu.o Jeu2048.o Jeu2048Plus.o JeuSokoban.o JeuTaquin.o Fonction.o

all: $(EXEC)

main :	$(OBJECTS)
	$(CC) $(CFLAGS) -o main Main.cpp $(OBJECTS)

%.o: %.cpp 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f *~
proper:	
	rm -f $(EXEC)
