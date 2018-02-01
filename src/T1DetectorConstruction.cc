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
#include "PhysicalConstants.h"


// Constructor
T1DetectorConstruction::T1DetectorConstruction()
  :G4UserDetectorConstruction(),
   fScoringVolume(0)
{ }

// Destructor
T1DetectorConstruction::~T1DetectorConstruction()
{ }


G4VPhysicalVolume* T1DetectorConstruction::Construct()
{
  
  //************************** Materials *************************************
  G4double z, a, fractionmass, density, pressure, temperature;
  G4String name, symbol;
  G4int nel, natoms;
  //Get nist material
  G4NistManager* nist = G4NistManager::instance();

  G4Material* Ag = nist->FindOrBuildMaterial("G4_Ag");
  G4Material* Ni = nist->FindOrBuildMaterial("G4_Ni");  

  // Vacuum and Air from 
  // http://www.apc.univ-paris7.fr/~franco/g4doxy4.10/html/examples_2extended_2eventgenerator_2_hep_m_c_2_m_c_truth_2src_2_detector_cons
  // truction_8cc_source.html
  
  // Air
  G4Element* elN = new G4Element("Nitrogen", "N", z = 7., a = 14.00*g/mole);
  GeElement* elO = new G4Element("Oxygen", "O", z = 16., a = 16.00*g/mole);
  density = 1.290*mg/cm3;
  G4Material* Air = new G4Material(name="Air", density, nel=2);
  Air->AddElement(elN, 0.7);
  Air->AddElement(elO, 0.3);

  // 4-May-2006 : We rename "Vacuum" as "G4vacuum" to avoid
  //              problems with Flugg.
  density     = 1.e-5*g/cm3;
  pressure    = 2.e-2*bar;
  temperature = STP_Temperature;  // From PhysicalConstants.h .
  G4Material* G4vacuum = new G4Material(name="G4vacuum", density, nel=1,
                                          kStateGas, temperature, pressure);
  G4vacuum->AddMaterial(Air, fractionmass=1.);

  // 18O Water
  density = 1.11*g/cm3;
  G4Element* el18O = new G4Element("18-Oxygen", "18-O", z=18., a = 18.0*g/mole); 
  G4Element* elH = new G4Element("Hydrogen", "H", z = 1., a = 1.01*g/mole);
  G4Material* O18Water = new GMaterial("H2-18O", density, nel = 2);
  O18Water -> AddElement(elH, natoms = 2);
  O18Water -> AddElement(el18O, natoms = 1);

  // variables
  G4double worldXYZ = 1.5*m;              // half of the world size
  G4double innerRadius = 0.00*mm;         // tubs inner radius
  G4Double targetRaduis = 9.50*mm;        // radius of the water target
  G4Double outerRadius = 10.00*mm;        // outer radius of the target chamber
  G4Double beamlineRadius = 10.10*mm;     // beamline vacuum radius
  G4Double targetLength = 1.41*mm;        // half length in Z of the water target (could be calculated here)
  G4Double chamberLength = 1.66*mm;       // half length in Z of the target chamber 0.5 mm chamber back thickness
  G4Double nickelfoilLength = 0.025*mm;   // half length in Z of the nickel foil
  G4Double beamlineLength = 0.9*WorldXYZ; //half length of the beamline
  G4Double startAngle = 0.*deg;           // full cylinder
  G4Double spanningAngle = 360.*deg;      // full cylinder

  G4Bool checkOverlaps = true;  

  // Air filled world
  G4box* solidWord = new G4Box("World", worldXYZ, worldXYZ, worldXYZ);
  G4LogicalWorld* logicWorld = new G4LogicalWorld(solidWorld, // solid 
						  Air,        // material
						  "World",    // name
						  0,          // field manager
						  0,          // sensitive detector
						  0);         // user limits

  G4PhysicalVolume* physicalWorld = new G4PVPlacement(0,               // rotation
						   G4ThreeVector(), // translation, at (0,0,0)
						   logicalWorld,    // logical volume
						   "World",         // name
						   0,               // mother physical volume
						   false,           // boolean operator
						   0,               // copy number
						   checkOverlaps);  // check for overlaps

  //Beamline
  G4Tubs* solidBeamline = new G4Tubs("Beamline", innerRadius, beamlineRadius, beamlineLength, startAngle, spanningAngle);
  G4LogicalWorld* logicBeamline = new G4LogicalWorld(solidBeamline, // solid
						 G4vacuum,      // material
						 "Beamline",    // name
						 0,             // field manager
						 0,             // sensitive detector
						 0);            // user limits

  new G4PVPlacement(0,                      // rotation
		    G4ThreeVector(0, 0, ?), // translation
		    logicBeamline,          // logic volume
		    "Beamline",             // name
		    logicWorld,             // mother volume
		    false,                  // boolean operation
		    0,                      // copy number
		    checkOverlaps);         // check for overlaps
  
  // Target chamber a silver cylinder
  G4Tubs* solidTargetChamber = new G4Tubs("TargetChamber", innerRadius, outerRadius, chamberLength, startAngle, spanningAngle); 
  G4LogicalWorld* logicTargetChamber = new G4LogicalWorld(solidTargetChamber, // solid
							  Ag,              // material
							  "TargetChamber",    // name
							  0,                  // field manager
							  0,                  // sensitive detector
							  0);                 // user limits

  new G4PVPlacement(0,                      // rotation
		    G4ThreeVector(0, 0, ?), // translation
		    logicTargetChamber,     // logical volume
		    "TargetChamber",        // name
		    logicBeamline,          // mother volume
		    false,                  // no boolean operator
		    0,                      // copy number
		    checkOverlaps);         // check for overlaps
                                                           
// Target chamber seal, nickel
  G4Tubs* solidTargetSeal = new G4Tubs("TargetSeal", innerRadius, outerRadius, nickelfoilLength, startAngle, spanningAngle); 
  G4LogicalWorld* logicTargetSeal = new G4LogicalWorld(solidTargetSeal,    // solid
						       Ni,              // material
						       "TargetSeal",       // name
						       0,                  // field manager
						       0,                  // sensitive detector
						       0);                 // user limits

  new G4PVPlacement(0,                      // rotation
		    G4ThreeVector(0, 0, ?), // translation
		    logicTargetSael,        // logical volume
		    "TargetSeal",           // name
		    logicBeamline,          // mother volume
		    false,                  // no boolean operator
		    0,                      // copy number
		    checkOverlaps);         // check for overlaps
                                                           
// Water target H2 18-O
  G4Tubs* solidWaterTarget = new G4Tubs("WaterTarget", innerRadius, targetRadius, targetLength, startAngle, spanningAngle); 
  G4LogicalWorld* logicWaterTarget = new G4LogicalWorld(solidWaterTarget,     // solid
							  O18Water,          // material DEFINE!!
							  "WaterTarget",      // name
							  0,                  // field manager
							  0,                  // sensitive detector
							  0);                 // user limits

  new G4PVPlacement(0,                      // rotation
		    G4ThreeVector(0, 0, ?), // translation
		    logicWaterTarget,       // logical volume
		    "WaterTarget",          // name
		    logicTargetChamber,     // mother volume
		    false,                  // no boolean operator
		    0,                      // copy number
		    checkOverlaps);         // check for overlaps

  // Scoring volume water target
  fscoringVolume = logicWaterTarget;

  return physicalWord;
}
