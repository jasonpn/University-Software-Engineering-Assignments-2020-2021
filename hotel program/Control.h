#ifndef CONTROL_H
#define CONTROL_H

#define MAX_ARR 256

#include "Hotel.h"
#include "ResManager.h"
#include "Recorder.h"
#include "Reservation.h"
#include "View.h"

/*
Control class to create a hotel, initialize it, add reservations and manage reservations by manager. 
*/

class Control
{
 public:
  Control();
  ~Control();
  void launch();

 private:
  void initHotel();
  View view;
  Hotel* hotel;
  ResManager* resMgr;
  Recorder* stayrec;
  Recorder* guestrec;
  Recorder* uprec;
};

#endif
