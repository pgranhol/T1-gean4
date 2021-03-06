// main function for the T1-project
// Activation of target hall due to 17 MeV protons on a water target
// Patric Granholm 21.2.2018

// Needs vis.mac

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"


#include "T1DetectorConstruction.hh"
#include "T1ActionInitialization.hh"
#include "T1SteppingVerbose.hh"
//#include "T1PrimaryGeneratorAction.hh"
//#include "T1PhysicsList.hh"
#include "QGSP_BERT_HP.hh"
#include "QGSP_BERT.hh"
#include "QGSP_BIC_HP.hh"
#include "Shielding.hh"

int main(int argc, char** argv)
{
  // Detect interactive mode (if no arguments) and define UI session
  //
  //  G4UIExecutive* ui = 0;
  //  if ( argc == 1 ) {
  //    ui = new G4UIExecutive(argc, argv);


  //#ifdef G4MULTITHREADED
  //  G4MTRunManager* runManager = new G4MTRunManager;
  //#else
  //  G4RunManager* runManager = new G4RunManager;
  //#endif

  G4Random::setTheEngine(new CLHEP::RanecuEngine);

  // Construct the default run manager
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  G4int nThreads = G4Threading::G4GetNumberOfCores();
  if (argc==3) nThreads = G4UIcommand::ConvertToInt(argv[2]);
  runManager->SetNumberOfThreads(nThreads);  
#else
  //my Verbose output class
  G4VSteppingVerbose::SetInstance(new T1SteppingVerbose);
  G4RunManager* runManager = new G4RunManager;
#endif

  //Mandatory initialization
  //Detector construction
  T1DetectorConstruction* det = new T1DetectorConstruction;
  runManager->SetUserInitialization(det);

  //Physics List
  //runManager->SetUserInitialization(new T1PhysicsList());

  // Physics list
  G4VModularPhysicsList* physicsList = new QGSP_BERT_HP;
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

  //T1PhysicsList* phys = new T1PhysicsList;  
  //  runManager->SetUserInitialization(phys);
  //runManager->SetUserInitialization(new T1ActionInitialization(det));

  //Action Initialization
  runManager->SetUserInitialization(new T1ActionInitialization(det));

  //Visualization initializaation
  //  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  //  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session
  //
  if (argc!=1) { 
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    //    UImanager->ApplyCommand("/control/execute init_vis.mac");
    //    ui->SessionStart();
    //    delete ui;

#ifdef G4VIS_USE
   G4VisManager* visManager = new G4VisExecutive;
   visManager->Initialize();
#endif

#ifdef G4UI_USE
      G4UIExecutive * ui = new G4UIExecutive(argc,argv);
      ui->SessionStart();
      delete ui;
#endif

#ifdef G4VIS_USE
     delete visManager;
#endif
  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted 
  // in the main() program !
  
//  delete visManager;
  delete runManager;
}  
