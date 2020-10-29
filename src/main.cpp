#include <cstdio>
#include <iostream>
#include "THMemory.h"

int main()
{ 
    int* p = NEW int;
    THTREENS::TH_HEAPDUMP();
    DELETE(p, __FILE__);
    return 0;
}