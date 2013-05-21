# Sudoku : main.o GestionCandidats.o
# 	gcc main.o GestionCandidats.o -o Sudoku
# 
# main.o : main.c GestionCandidats.c
# 	gcc -c main.c -o main.o
# 
# GestionCandidats.o : GestionCandidats.c GestionCandidats.h
# 	gcc GestionCandidats.c GestionCandidats.h -o GestionCandidats.o

#effacer les fichers '*.o'
clean : 
	rm -r */*.o; rm *.o; rm */TEST
