// Header file for T1DetectorMessenger.cc based on Hadr03
// Patric Granholm 29.3.2018
 
#ifndef T1DetectorMessenger_h
#define T1DetectorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class T1DetectorConstruction;
class G4UIdirectory;
class G4UIcommand;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;



class T1DetectorMessenger: public G4UImessenger
{
  public:
  
    T1DetectorMessenger(DetectorConstruction* );
   ~T1DetectorMessenger();
    
    virtual void SetNewValue(G4UIcommand*, G4String);
    
  private:
  
    T1DetectorConstruction*      fDetector;
    
    G4UIdirectory*             fTesthadDir;
    G4UIdirectory*             fDetDir;
    G4UIcmdWithAString*        fMaterCmd;
    G4UIcmdWithADoubleAndUnit* fSizeCmd;
    G4UIcommand*               fIsotopeCmd;    
};

#endif
