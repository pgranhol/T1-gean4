// Header for T1GammaNuclearPhysics.cc
// Patric Granholm 29.3.2018

#ifndef T1GammaNuclearPhysics_h
#define T1GammaNuclearPhysics_h 1

#include "globals.hh"
#include "G4VPhysicsConstructor.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class T1GammaNuclearPhysics : public G4VPhysicsConstructor
{
  public:
    T1GammaNuclearPhysics(const G4String& name="gamma");
   ~T1GammaNuclearPhysics();

  public:
    virtual void ConstructParticle() { };
    virtual void ConstructProcess();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
