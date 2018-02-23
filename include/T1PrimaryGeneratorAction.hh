// Header file for PrimaryGeneratorAction.cc
// Patric Granholm 22.2.2018

#ifndef T1PrimaryGeneratorAction_h
#define T1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"

class G4ParticleGun;
class G4Event;

class T1PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
 public:
   T1PrimaryGeneratorAction();
  ~T1PrimaryGeneratorAction();  

//methods
   virtual void GeneratePrimaries(G4Event*);
  
 public:
//data members
   G4ParticleGun* fparticleGun; //pointer to G4 service class

};

#endif
