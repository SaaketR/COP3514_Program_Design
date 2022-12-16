readline.o: readline.c readline.h
	gcc -c readline.c
student.o: student.c student.h
	gcc -c student.c
project10_roster.o: project10_roster.c student.h
	gcc -c project10_roster.c
project10_roster: project10_roster.o readline.o student.o
	gcc -o project10_roster project10_roster.o readline.o student.o