// T1 Physics List 
// Patric Granholm 21.2.2018
//
// 17 MeV protons on water target
// Requires
// -low energy neutron physics
// -electromagnetic interractions
// -protons, neutrons, gamma, electrons(?)
// -hardon elastic and inelastic collisions

// Own headers
#include "T1PhysicsList.hh"

// Physics packages

#include "G4HadronPhysicsQGSP_BERT_HP.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"


#include "G4SystemOfUnits.hh"

T1PhysicsList::T1PhysicsList()
: G4VModularPhysicsList(){

  G4int verb = 1;

  SetDefaultCutValue(0.7*mm);
  SetVerboseLevel(verb);

  RegisterPhysics(new G4HadronPhysicsQGSP_BERT_HP(verb));
}

T1PhysicsList::~T1PhysicsList(){}


