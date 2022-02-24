a2:	main.o Control.o View.o Telco.o Subscriber.o Array.o Call.o Date.o Time.o 
	g++ -o a2 main.o Control.o View.o Telco.o Subscriber.o Array.o Call.o Date.o Time.o 

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h Subscriber.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

Telco.o: Telco.cc Telco.h Subscriber.h Array.h Call.h
	g++ -c Telco.cc

Subscriber.o: Subscriber.cc Subscriber.h Array.h Call.h
	g++ -c Subscriber.cc

Array.o: Array.cc Array.h Call.h
	g++ -c  Array.cc

Call.o: Call.cc Call.h Date.h Time.h
	g++ -c Call.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Time.o: Time.cc Time.h
	g++ -c Time.cc

clean:
	rm -f *.o *~ a2
