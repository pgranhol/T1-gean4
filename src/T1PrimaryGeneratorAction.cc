//Primary Action Generator for mgc-20-T1
//17 MeV proton beam, beam diameter 1.0 cm
// Patric Granhoolm 13.2.2018

#include "T1PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

T1PrimaryGeneratorAction::T1PrimaryGeneratorAction()  : G4VUserPrimaryGeneratorAction(),
    fparticleGun(0)
{
  G4int nofParticles = 1;
  fparticleGun = new G4ParticleGun(nofParticles);
  
  G4String particleName = "proton";
  G4double energy = 17*MeV;
  G4ThreeVector position = G4ThreeVector(-1.3*m, 0, -1.27*m); //target at -1.3*m, 0, -1.25
  G4ThreeVector momentumDirection = G4ThreeVector(0,0,1);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
  fparticleGun -> SetParticleDefinition(particle);
  fparticleGun -> SetParticleEnergy(energy);
  fparticleGun -> SetParticlePosition(position);
  fparticleGun -> SetParticleMomentumDirection(momentumDirection);
}

T1PrimaryGeneratorAction::~T1PrimaryGeneratorAction()
{
  delete fparticleGun;
}

void T1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //function called et the beginning of event
  fparticleGun->GeneratePrimaryVertex(anEvent); 
}
