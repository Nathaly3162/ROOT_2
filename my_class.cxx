#include "my_class.h"
#include "TMath.h"

ClassImp(my_class)

my_class::my_class() : px(0.0), py(0.0), pz(0.0) {
}

my_class::my_class(Double_t px, Double_t py, Double_t pz) : px(px), py(py), pz(pz) {
}

Double_t my_class::GetMagnitude() const {
    return TMath::Sqrt(px * px + py * py + pz * pz);
}

my_class::~my_class() {
}