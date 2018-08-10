//Action Initialization for T1 project
//21.2.2018 Patric Granholm

#include "T1ActionInitialization.hh"
#include "T1RunAction.hh"
#include "T1PrimaryGeneratorAction.hh"
#include "T1SteppingAction.hh"
#include "T1SteppingVerbose.hh"

// Constructor
T1ActionInitialization::T1ActionInitialization(T1DetectorConstruction* detector)
  :G4VUserActionInitialization(),
   fDetector(detector)
{}

//Destructor
T1ActionInitialization::~T1ActionInitialization()
{}

void T1ActionInitialization::BuildForMaster() const
{
  T1RunAction* runAction = new T1RunAction(fDetector,0);
  SetUserAction(runAction);
}

void T1ActionInitialization::Build() const
{
  T1PrimaryGeneratorAction* primary = new T1PrimaryGeneratorAction();
  SetUserAction(primary);
    
  T1RunAction* runAction = new T1RunAction(fDetector, primary);
  SetUserAction(runAction);
  
  T1SteppingAction* steppingAction = new T1SteppingAction();
  SetUserAction(steppingAction);
}

G4VSteppingVerbose* T1ActionInitialization::InitializeSteppingVerbose() const
{
  return new T1SteppingVerbose();
}  
