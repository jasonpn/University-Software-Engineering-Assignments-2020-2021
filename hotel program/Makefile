a4:	main.o Control.o View.o Recorder.o Reservation.o ResManager.o Hotel.o RoomArray.o Room.o Guest.o Date.o
	g++ -o a4 main.o Control.o View.o Recorder.o Reservation.o ResManager.o Hotel.o RoomArray.o Room.o Guest.o Date.o

main.o:	main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h Hotel.h ResManager.h Recorder.h View.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

Recorder.o: Recorder.cc Recorder.h Reservation.h
	g++ -c Recorder.cc

Reservation.o: Reservation.cc Reservation.h Guest.h Room.h Date.h
	g++ -c Reservation.cc

ResManager.o: ResManager.cc ResManager.h defs.h Hotel.h
	g++ -c ResManager.cc

Hotel.o: Hotel.cc Hotel.h Guest.h RoomArray.h ResManager.h
	g++ -c Hotel.cc

RoomArray.o: RoomArray.cc RoomArray.h Room.h defs.h
	g++ -c RoomArray.cc

Room.o: Room.cc Room.h defs.h
	g++ -c Room.cc

Guest.o: Guest.cc Guest.h 
	g++ -c Guest.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc
clean:
	rm -f *.o *~ a4
