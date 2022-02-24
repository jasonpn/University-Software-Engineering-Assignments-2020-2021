#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include "ResManager.h"
#include "Hotel.h"

ResManager::ResManager(Hotel* h){
  hotel = h;
  numReserves = 0;
}

ResManager::~ResManager(){
  for(int i = 0; i<numReserves; i++){
    delete reserves[i];
  }

  for(int i =0; i<recorders.size(); i++){
    delete recorders[i];
  }
}

void ResManager::setHotel(Hotel* h){
  hotel = h;
}

bool ResManager::findDate(Date* d){
  if(numReserves == 0){
    return false;
  }

  for(int i = 0; i<numReserves; i++){
    if(reserves[i]->getArrive() == d){
      return true;
    }
  }

  return false;
}

bool ResManager::add(Reservation* r){
  if (numReserves == MAX_ARR){
    return false;
  }

  if (numReserves == 0){
    reserves[numReserves] = r;
    numReserves++;
  }

  for(int i = 0; i<numReserves; i++){
    if(r->lessThan(reserves[i])){
      for(int j = numReserves; j>i; j--){
	reserves[j] = reserves[j-1];
      }
      reserves[i] = r;
      numReserves++;
      return true;
    }
  }

  reserves[numReserves] = r;
  numReserves++;
  return true;
  
}

void ResManager::addReservation(string n, int y, int m, int d, int stay, ReqRoomType req){
  if(stay > 0 && stay < 31){
    Date* newd = new Date(d,m,y);
    Guest* g = new Guest();

    for(int i =0; i< hotel->getRooms().getSize(); i++){
      if(hotel->getRooms().get(i)->getRoomType() == req){
	if(!findDate(newd)){
	  if(hotel->findGuest(n, &g)){
	    Reservation* newr = new Reservation(g, hotel->getRooms().get(i), newd, stay);
	    add(newr);
	    int pts;
	    hotel->getRooms().get(i)->computePoints(pts);
	    int npts = pts * stay;
	    g->addPts(npts);
	    notify(newr);
	    cout<<"RESERVED"<<endl;
	  }
	  else{
	    cout<<"Error: Guest " << g->getName() << " does not exist" << endl;
	  }
	}
	else{
	  cout<<"Error: Date not available" << endl;
	}
      }
      else{
	cout<<"Error: No room of matching type available" << endl;

      }
    }   
  }
  else{
    
  }
}

void ResManager::subscribe(Recorder* r){
  recorders.push_back(r);
}

void ResManager::print(){
  for(int i = 0; i<numReserves; i++){
    reserves[i]->print();
  }
}

void ResManager::printRecords(){
  for(int i = 0; i<recorders.size(); i++){
    recorders[i]->printRecords();
  }
}

void ResManager::notify(Reservation* r){
  for(int i = 0; i<recorders.size(); i++){
    recorders[i]->update(r);
  }
}
