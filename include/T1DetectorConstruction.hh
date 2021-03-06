// Header for T1DetectorConstruction

#ifndef T1DetectorConstruction_h
#define T1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;

// The detector construction class

class T1DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    T1DetectorConstruction();
    virtual ~T1DetectorConstruction();
    virtual G4VPhysicalVolume* Construct();
    G4LogicalVolume* GetScoringVolume() const {return fScoringVolume;}
    G4Material* GetMaterial() {return fMaterial;}
  
  private:
    G4Material* fMaterial;
  protected:
    G4LogicalVolume* fScoringVolume; //fLBox in Hard03
};

#endif
  
