//Primary Action Generator for mgc-20-T1
//17 MeV proton beam, beam diameter 1.0 cm
// Patric Granhoolm 13.2.2018

#include "T1PrimaryGeneratorAction.hh"

#include "G6Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemsOfUnits.hh"

T1PrimaryGeneratotAction::T1PrimaryGeneratorAction(
                      const G4String& particleName,    // Protons 
		      G4 double energy,                // 17 MeV protons
		      G4ThreeVector position,          // Source position
		      G4ThreeVector momentumDirection) // Direction of particle momentum
  : G4VUserPrimaryGenerationAction(),
    fparticleGun(0)
{
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);
  
  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
  fParticleGun -> SetParticleDefinition(particle);
  fParticleGun -> SetParticleEnergy(energy);
  fParticleGun -> SetParticlePosition(position);
  fparticleGun -> SetParticleMomentumDirection(momentumDirection);
}

T1PrimaryGeneratorAction::~T1PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void T1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //function called et the beginning of event
  fParticleGun->GeneratePrimaryVertex(anEvent); 
}
