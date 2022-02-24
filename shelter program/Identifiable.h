#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

#include <string>

/*
Identifiable class creates and keep track of unique ID for animals and clients
*/
class Identifiable{
 public:
  Identifiable(string= "A", int = 0);
  string getId();
 protected:
  string id;
 private:
  static int nextId;
};

#endif
