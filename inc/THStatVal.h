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


//
#define TH_SUP_SELF_BALANCE (0)
#define TH_UNSUP_SELF_BALANCE (1)

//Debug Info
//warning
#define THDEBUG
#define THWARNING(fmt, ...) printf("\033[35m<WARN: %s, %d>"fmt"\n\033[0m", __FUNCTION__, __LINE__, ##__VA_ARGS__);
#define THERR(fmt, ...) printf("\033[36m<ERR: %s, %d>"fmt"\n\033[0m", __FUNCTION__, __LINE__, ##__VA_ARGS__);
#endif //THSTATVAL_H_