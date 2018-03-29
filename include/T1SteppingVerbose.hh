// Header file for T1SteppingVerbose.cc based on Hadr03
// Patric Granholm

#ifndef T1SteppingVerbose_h
#define T1SteppingVerbose_h 1

#include "G4SteppingVerbose.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class T1SteppingVerbose : public G4SteppingVerbose {

public:   

  T1SteppingVerbose();
 ~T1SteppingVerbose();
 
  virtual void TrackingStarted();
  virtual void StepInfo();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
