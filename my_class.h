#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__

#include "TObject.h"

class my_class : public TObject {
public:
    my_class(); // default constructor
    my_class(Double_t px, Double_t py, Double_t pz); // constructor with initialization
    virtual ~my_class(); // destructor

    // Add members for px, py, pz
    Double_t px;
    Double_t py;
    Double_t pz;

    // Member function to calculate the magnitude
    Double_t GetMagnitude() const;

    ClassDef(my_class, 1); // my_class
};

#endif // __MY_CLASS_H__