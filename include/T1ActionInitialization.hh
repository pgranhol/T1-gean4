// Action Initialization T1-project
//
// 21.2.2018 Patric Granholm

#ifndef T1ActionInitialization_h
#define T1ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class T1DetectorConstruction;
class G4VSteppingVerbose;

class T1ActionInitialization : public G4VUserActionInitialization
{
  public:
  T1ActionInitialization(T1DetectorConstruction* detector);
  virtual ~T1ActionInitialization();

  virtual void BuildForMaster() const;
  virtual void Build() const;

  virtual G4VSteppingVerbose* InitializeSteppingVerbose() const;
   
  private:
    T1DetectorConstruction* fDetector;
};

#endif

  

