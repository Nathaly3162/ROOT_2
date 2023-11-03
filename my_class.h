#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__

#include "TObject.h"

class my_class : public TObject {
public:
    my_class(); 
    my_class(Double_t px, Double_t py, Double_t pz); 
    virtual ~my_class(); 

    Double_t px;
    Double_t py;
    Double_t pz;

    Double_t GetMagnitude() const;

    ClassDef(my_class, 1);
};

#endif 