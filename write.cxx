#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include "my_class.h"

void writeTree() {
    // Initialize your object as a pointer
    my_class* myObject = new my_class(0.0, 0.0, 0.0); // Initialize with default values

    // Create your root file
    TFile* rootFile = new TFile("tree_file.root", "RECREATE");

    // Create your TTree
    TTree* tree = new TTree("tree", "My Tree Title");

    // Define branches for the TTree
    tree->Branch("px", &myObject->px, "px/D");
    tree->Branch("py", &myObject->py, "py/D");
    tree->Branch("pz", &myObject->pz, "pz/D");

    // Initialize the random number generator
    TRandom3 randomGenerator;

    // Number of events you want
    Int_t nEvents = 100;

    // For loop to fill the tree with random data
    for (Int_t i = 0; i < nEvents; i++) {
        // Generate random data
        myObject->px = randomGenerator.Gaus(0, 0.02);
        myObject->py = randomGenerator.Gaus(0, 0.02);
        myObject->pz = randomGenerator.Gaus(0, 0.02);

        // Fill the tree with the current values of px, py, and pz
        tree->Fill();
    }

    // Remember to delete your object to prevent memory leaks
    delete myObject;

    // Save the TTree and close the root file
    rootFile->Write();
    rootFile->Close();
}