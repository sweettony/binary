#ifndef THSTATVAL_H_
#define THSTATVAL_H_
#include "stddef.h"

//base type redefine
#ifndef THSINT
typedef signed int THSINT;
#endif

#ifndef THLLUINT
typedef unsigned int THUINT;
#endif

#ifndef THLLUINT
typedef long long unsigned int THLLUINT;
#endif

//state value
#define TH_OK   (0)
#define TH_FAIL (1)

#endif //THSTATVAL_H_