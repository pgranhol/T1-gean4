// Header for T1DetectorConstruction

#ifndef T1DetectorConstruction_h
#define T1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

// The detector construction class

class T1DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    T1DetectorConstruction();
    virtual ~T1DetectorConstruction();
    virtual G4VPhysicalVolume* Construct();
    G4LogicalVolume* GetScoringVolume() const {return fScoringVolume;}
    
  protected:
  G4LogicalVolume* fScoringVolume;
};

#endif
  
