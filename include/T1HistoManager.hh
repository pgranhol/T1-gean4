// header file for T1HistoManager.cc
// Patric Granholm 27.2.2018
// from "Hadr03" 

#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

#include "g4root.hh"
//#include "g4xml.hh" To check!!


class T1HistoManager
{
  public:
   T1HistoManager();
  ~T1HistoManager();

  private:
    void Book();
    G4String fFileName;
};

#endif
