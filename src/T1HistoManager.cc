// Histogram manager for T1 simulation
// Patric Granholm 27.3.2018
// from "Hadr03"
 
#include "T1HistoManager.hh"
#include "G4UnitsTable.hh"

// constructor
T1HistoManager::T1HistoManager()
  : fFileName("NeutronEnergy")
{
  Book();
}

T1HistoManager::~T1HistoManager()
{

}

void T1HistoManager::Book()
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetFileName(fFileName);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetActivation(true);

  // Define histograms start values
  const G4int kMaxHisto = 13;
  const G4String id[] = {"0","1","2","3","4","5","6","7","8","9",
                         "10","11","12"};
  const G4String title[] = 
                { "dummy",                                          //0
                  "kinetic energy of scattered primary particle",   //1
                  "kinetic energy of gamma",                        //2
                  "kinetic energy of neutrons",                     //3
                  "kinetic energy of protons",                      //4
                  "kinetic energy of deuterons",                    //5
                  "kinetic energy of alphas",                       //6
                  "kinetic energy of nuclei",                       //7
                  "kinetic energy of mesons",                       //8
                  "kinetic energy of baryons",                      //9
                  "Q = Ekin out - Ekin in",                         //10
                  "Pbalance = mag(P_out - P_in)",                   //11
                  "atomic mass of nuclei"                           //12
                 };  

  // Default values (to be reset via /analysis/h1/set command)               
  G4int nbins = 100;
  G4double vmin = 0.;
  G4double vmax = 100.;

  // Create all histograms as inactivated 
  // as we have not yet set nbins, vmin, vmax
  for (G4int k=0; k<kMaxHisto; k++) {
    G4int ih = analysisManager->CreateH1(id[k], title[k], nbins, vmin, vmax);
    analysisManager->SetH1Activation(ih, false);
  }
}
