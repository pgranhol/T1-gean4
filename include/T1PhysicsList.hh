// Physics List definition for 17 MeV proton beam on water
// Neutron production from the target and activation
// Neutron activation of the target hall
// 20.2.2018 Patric Granholm

// Modular physics list
//
#ifndef T1PhysicsList_h
#define T1PhysicsList_h

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class G4VPhysicsConstructor;

class T1PhysicsList: public G4VModularPhysicsList
{
public:
  T1PhysicsList();
  ~T1PhysicsList();

};

#endif
