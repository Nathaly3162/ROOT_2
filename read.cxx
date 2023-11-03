#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TCanvas.h>
#include "my_class.h"

void readTree() {
    // Open your file
    TFile* rootFile = TFile::Open("tree_file.root", "READ");

    // Get your TTree
    TTree* tree = (TTree*)rootFile->Get("tree");

    // Set the branch address
    Double_t px, py, pz;

    tree->SetBranchAddress("px", &px);
    tree->SetBranchAddress("py", &py);
    tree->SetBranchAddress("pz", &pz);

    // Exercise 8: Fill a TH2 with px and py and draw it
    TCanvas* c1 = new TCanvas("c1", "Scatter Plot", 800, 600);
    TH2D* hist2D = new TH2D("hist2D", "Scatter plot of px vs py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    Int_t N = tree->GetEntries();
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);
        hist2D->Fill(px, py);
    }

    hist2D->Draw("COLZ");
    c1->SaveAs("scatter_plot.png");

    // Exercise 9: Use TTree::Draw to draw a scatter plot of px*py vs pz with a magnitude criterion
    TCanvas* c2 = new TCanvas("c2", "Scatter Plot With Criterion", 800, 600);
    TH2D* hist2DWithCriterion = new TH2D("hist2DWithCriterion", "Scatter Plot of px*py vs pz", 100, -0.1, 0.1, 100, -0.1, 0.1);

    tree->Draw("px*py:pz", "TMath::Sqrt(px*px + py*py + pz*pz) > 0.02", "COLZ");
    c2->SaveAs("scatter_plot_with_criterion.png");

    // Clean up
    c1->Close();
    c2->Close();
    rootFile->Close();
}