#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include "my_class.h"

void writeTree() {
    my_class* myObject = new my_class(0.0, 0.0, 0.0); // Initialize with default values

    TFile* rootFile = new TFile("tree_file.root", "RECREATE");

    TTree* tree = new TTree("tree", "My Tree Title");

    tree->Branch("px", &myObject->px, "px/D");
    tree->Branch("py", &myObject->py, "py/D");
    tree->Branch("pz", &myObject->pz, "pz/D");

    TRandom3 randomGenerator;

    Int_t nEvents = 100;

    for (Int_t i = 0; i < nEvents; i++) {
        myObject->px = randomGenerator.Gaus(0, 0.02);
        myObject->py = randomGenerator.Gaus(0, 0.02);
        myObject->pz = randomGenerator.Gaus(0, 0.02);

        tree->Fill();
    }

    delete myObject;

    rootFile->Write();
    rootFile->Close();
}