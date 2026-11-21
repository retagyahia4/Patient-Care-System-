#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int severity; // 1 to 10 (10 is most severe)
};

#endif