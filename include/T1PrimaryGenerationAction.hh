// Header file for PrimaryGenerationAction.cc
// Patric Granholm 13.2.2018

#ifndef T1PrimaryGeneratorAction_h
#define T1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"

class G4ParticleGun;
class G4Event;

class T1PrimaryGenerationAction : public G4VUserPrimaryGenerationAction
{
 public:
   T1PrimaryGenerationAction(
     const G4String& particleName = "geantino", // Check this 
     G4 double energy = 17*MeV,
     G4ThreeVector position = G4ThreeVector(0, 0, 0),
     G4ThreeVector momentumDirection G4ThreeVector(0, 0, 1));
  ~T1PrimaryGeneratorAction();  
}
//methods
   virtual void GeneratePrimaries(G4Event*);
  
 public:
//data members
   G4ParticleGun* fparticleGun; //pointer to G4 service class

};

#endif
