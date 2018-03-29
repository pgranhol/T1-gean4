//Run action for the T1 project
//Patric Granholm 7.3.2018 histograms from Hadr03

#include "T1RunAction.hh"
#include "T1PrimaryGeneratorAction.hh"
#include "T1DetectorConstruction.hh"
#include "T1Run.hh" // to be written
#include "T1RunMessenger.hh" // to be written
#include "T1HistoManager.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

TIRunAction::T1RunAction(DetectorConstruction* det, PrimaryGeneratorAction* prim)
  :G4UserRunAction(),
   fDetector(det), fPrimary(prim), fRun(0), fHistoManager(0),
   fRunMessenger(0), fPrint(true)   
{
  fHistoManager = new HistoManager();
  fRunMessenger = new RunMessenger(this);
}

T1RunAction::~RunAction()
{
  delete fHistoManager;
  delete fRunMessenger;
}

G4Run* T1RunAction::GenerateRun()
{
  fRun = new Run(fDetector);
  return fRun;

void T1RunAction::BeginOfRunAction(const G4Run*)
{
  //random number is not stored
  //G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  // show Rndm status
  if (isMaster) G4Random::showEngineStatus(); 

  // keep run condition
  if (fPrimary) { 
    G4ParticleDefinition* particle 
      = fPrimary->GetParticleGun()->GetParticleDefinition();
    G4double energy = fPrimary->GetParticleGun()->GetParticleEnergy();
    fRun->SetPrimary(particle, energy);

  //histograms
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->IsActive() ) {
    analysisManager->OpenFile();
  }     
}

void T1RunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;
  
  //save histograms      
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->IsActive() ) {
    analysisManager->Write();
    analysisManager->CloseFile();
  }
      
  // show Rndm status
  if (isMaster) G4Random::showEngineStatus();  

  const T1PrimaryGeneratorAction* generatorAction
    = static_cast<const T1PrimaryGeneratorAction*>
    (G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());  
}

void RunAction::SetPrintFlag(G4bool flag)
{ 
  fPrint = flag;
}
 
