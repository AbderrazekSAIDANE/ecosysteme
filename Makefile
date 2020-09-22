### AIDE ###
#	$@ : le nom de la cible
#	$< : le nom de la 1ère dépendance
#	$ˆ : la liste des dépendances
#	$* : le nom du fichier sans suffixe

# options de compilation
CC = gcc
CCFLAGS = -Wall
CCFLAGS2 = -Werror -std=c17 -pedantic

PROJ = DOUAILLY-Algo-TP3
# fichiers du projet
SRC = principal.c aleatoire.c ecosys.c
OBJ = $(SRC:.c=.o)
EXEC = systeme.out

# règles supplémentaires
all: $(EXEC)

clean:
	rm -rf $(OBJ)

mproper:
	rm -rf $(EXEC) $(OBJ)

zip:
	make mproper
	zip -r ../$(PROJ).zip .
	make
	

# édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^

# règles de compilation
principal.o: aleatoire.h
aleatoire.o: aleatoire.h
ecosys.o: ecosys.h aleatoire.h
%.o: %.c
	$(CC) $(CCFLAGS) $(CCFLAGS2) -o $@ -c $<
