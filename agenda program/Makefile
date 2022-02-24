a1:	main.o Agenda.o Calendar.o Date.o
	g++ -o a1 main.o Agenda.o Calendar.o Date.o

main.o:	main.cc Agenda.h
	g++ -c main.cc

Agenda.o: Agenda.cc Agenda.h Calendar.h Date.h
	g++ -c Agenda.cc

Calendar.o: Calendar.cc Calendar.h Date.h
	g++ -c Calendar.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f *.o *~ a1 
