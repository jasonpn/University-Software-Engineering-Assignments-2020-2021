fp:	main.o Control.o View.o ReportThree.o ReportTwo.o ReportOne.o ReportGenerator.o Record.o
	g++ -o fp main.o Control.o View.o ReportThree.o ReportTwo.o ReportOne.o ReportGenerator.o Record.o

main.o: main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h View.h ReportGenerator.h ReportOne.h ReportTwo.h ReportThree.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

ReportThree.o: ReportThree.cc ReportThree.h ReportGenerator.h
	g++ -c ReportThree.cc

ReportTwo.o: ReportTwo.cc ReportTwo.h ReportGenerator.h
	g++ -c ReportTwo.cc

ReportOne.o: ReportOne.cc ReportOne.h ReportGenerator.h
	g++ -c ReportOne.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Map.h Record.h ReportData.h
	g++ -c ReportGenerator.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

clean:
	rm -f *.o *~ fp
