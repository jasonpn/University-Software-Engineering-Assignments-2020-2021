a3:	main.o Control.o View.o Shelter.o MatchListByClient.o MatchListByScore.o MatchList.o Match.o Client.o Animal.o CriteriaArray.o Criteria.o Identifiable.o
	g++ -o a3 main.o Control.o View.o Shelter.o MatchListByClient.o MatchListByScore.o MatchList.o Match.o Client.o Animal.o CriteriaArray.o Criteria.o Identifiable.o

main.o: main.cc Control.h
	g++ -c main.cc

Control.o: Control.cc Control.h View.h Shelter.h Animal.h Client.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

Shelter.o: Shelter.cc Shelter.h MatchList.h Animal.h Client.h
	g++ -c Shelter.cc

MatchListByClient.o: MatchListByClient.cc MatchListByClient.h MatchList.h
	g++ -c MatchListByClient.cc

MatchListByScore.o: MatchListByScore.cc MatchListByScore.h MatchList.h
	g++ -c MatchListByScore.cc

MatchList.o: MatchList.cc MatchList.h Match.h
	g++ -c MatchList.cc

Match.o: Match.cc Match.h Animal.h Client.h
	g++ -c Match.cc

Client.o: Client.cc Client.h Identifiable.h CriteriaArray.h
	g++ -c Client.cc

Animal.o: Animal.cc Animal.h Identifiable.h defs.h
	g++ -c Animal.cc

CriteriaArray.o: CriteriaArray.cc CriteriaArray.h Criteria.h defs.h
	g++ -c CriteriaArray.cc

Criteria.o: Criteria.cc Criteria.h
	g++ -c Criteria.cc

Identifiable.o: Identifiable.cc Identifiable.h
	g++ -c Identifiable.cc;

clean:
	rm -f *.o *~ a3
