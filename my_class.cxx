#include "my_class.h"
#include "TMath.h"

ClassImp(my_class)

my_class::my_class() : px(0.0), py(0.0), pz(0.0) {
    // Default constructor, initializes px, py, pz to 0.
}

my_class::my_class(Double_t px, Double_t py, Double_t pz) : px(px), py(py), pz(pz) {
    // Constructor with initialization, sets px, py, pz based on provided values.
}

// Member function to calculate the magnitude
Double_t my_class::GetMagnitude() const {
    return TMath::Sqrt(px * px + py * py + pz * pz);
}

my_class::~my_class() {
    // Destructor, you can add any cleanup code here if needed.
}