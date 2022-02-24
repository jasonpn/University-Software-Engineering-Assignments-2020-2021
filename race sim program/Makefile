a3:	main.o Race.o View.o Array.o Runner.o MoveBehaviour.o Position.o
	g++ -Wall -o a3 main.o Race.o View.o Array.o Runner.o MoveBehaviour.o Position.o

main.o: main.cc Race.h
	g++ -Wall -c main.cc

Race.o: Race.cc Race.h View.h Array.h Position.h
	g++ -Wall -c Race.cc

View.o: View.cc View.h Position.h
	g++ -Wall -c View.cc

Array.o: Array.cc Array.h Runner.h
	g++ -Wall -c Array.cc

Runner.o: Runner.cc Runner.h MoveBehaviour.h Position.h
	g++ -Wall -c Runner.cc

MoveBehaviour.o: MoveBehaviour.cc MoveBehaviour.h Position.h
	g++ -Wall -c MoveBehaviour.cc

Position.o: Position.cc Position.h
	g++ -Wall -c Position.cc

clean:
	rm -f *.o *~ a3
