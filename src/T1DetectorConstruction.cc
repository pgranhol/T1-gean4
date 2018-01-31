//
// Detector construction for MGC-20 detectorposition T1 
//
// Production of 18F
// Gadolinia using a proton beam from the MGC-20 cyclotron and water target system (PET
// 1054). An amount of 800 mg [18O]H2O was irradiated for about 30 min using a particle beam
// current of 10 &#956;A. The water target chamber is made of silver and the water volume is
// sealed with a 50 &#956;m thick nickel foil (Goodfellow Cambridge Limited, NI000391,
// purity 99.98%). The foil was cooled
// with a flow of helium gas. The proton energy incident on the nickel foil was about 16.6
// MeV and on the water 15.7 MeV (SRIM-2006.02). The water was purchased
// from Rotem Industries Ltd. (Lot #: 14-1445) and contained 98.3 atom% of 18O, 1.0
// atom% of 17O and 0.7 atom% of 16O. The elemental impurities in the water were
// measured by the manufacturer. The metal impurities were < 0.1 mg/L."
//

#include "T1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolyme.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

T1DetectorConstruction::T1DetectorConstruction()
  :G4UserDetectorConstruction(),
   fScoringVolume(0)
{ }

T1DetectorConstruction::~T1DetectorConstruction()
{ }


G4PhysicalVolume* T1DetectorConstruction::Construct()
{
  // variables
  G4double WorldXYZ = 3.0*m; // world size
  G4Double innerRaduis = 9.50*mm; // inner radius of the target chamber
  G4Double outerRadius = 10.00*mm; // outer radius of the target chamber
  G4Double hz = 0.5*mm; // half length in Z
  G4Double startAngle = 0.*deg;
  G4Double spanningAngle = 360.*deg; // full cylinder

  // Air filled world
  G4box* solidWord = new G4Box("World",0.5*WorldXYZ,0.5*WorldXYZ,0.5*WoerldXYZ);
  G4LogicalWorld* logicWorld = new G4LogicalWorld(solidWorld, air, "World", 0, 0, 0);
  G4PVPlacement* physicalWorld = new G4PVPlacement(0, G4ThreeVector(), logicalWorld, "World", 0, false, 0);

  // Target chamber a silver cylinder seald with a nickel foil

  G4Tubs* solidTargetChamber = new G4Tubs("TargetChamber", innerRadius, outerRadius, hz, startAngle, spanningAngle); 

test
