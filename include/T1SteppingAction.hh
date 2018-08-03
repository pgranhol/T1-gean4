// Header for T1SteppingAction.cc based on Hadr03
// Patric Granholm 29.3.2018

#ifndef T1SteppingAction_h
#define T1SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include <map>

class G4ParticleDefinition;

class T1SteppingAction : public G4UserSteppingAction
{
  public:
    T1SteppingAction();
   ~T1SteppingAction();

    virtual void T1UserSteppingAction(const G4Step*);
    
  private:
    std::map<G4ParticleDefinition*,G4int> fParticleFlag;    
};

#endif
