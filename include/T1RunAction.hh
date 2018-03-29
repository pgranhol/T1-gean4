// T1 project
// Header for T1RunAction.cc
// Patric Granholm 7.3.2018

#ifndef T1RunAction_h
#define T1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class T1RunAction : public G4UserRunAction
{
 public:
  T1RunAction();
  virtual ~T1RunAction();
  
  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);
};

#endif