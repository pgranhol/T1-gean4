// T1 project
// Header for T1RunAction.cc
// Patric Granholm 7.3.2018

#ifndef T1RunAction_h
#define T1RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4VProcess.hh"
#include <map>
#include "globals.hh"

class T1DetectorConstruction;
class T1Run;
class T1RunMessenger;
class T1PrimaryGeneratorAction;
class T1HistoManager;
class G4Run;

class T1RunAction : public G4UserRunAction
{
 public:
  T1RunAction(T1DetectorConstruction*, T1PrimaryGeneratorAction*);
  virtual ~T1RunAction();

 public:
   virtual G4Run* GenerateRun();   
   virtual void BeginOfRunAction(const G4Run*);
   virtual void EndOfRunAction(const G4Run*);
  
   void SetPrintFlag(G4bool);
                                
 private:
    T1DetectorConstruction*      fDetector;
    T1PrimaryGeneratorAction*    fPrimary;
    T1Run*                       fRun;        
    T1HistoManager*              fHistoManager;
    T1RunMessenger*              fRunMessenger;
     
    G4bool   fPrint;      //optional printing 

};

#endif
