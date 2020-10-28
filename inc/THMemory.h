#ifndef THMEMORY_H_
#define THMEMORY_H_

#include <string>
#include <map>
#include <cstdlib>

#include "THStatVal.h"

namespace THTREENS
{
    typedef std::map<std::string, THLLUINT> STDMAP_TH_HMU;
    extern std::map<std::string, THLLUINT>  g_th_heap_memory_usage;
}


template<typename T>
T* THMALLOC(std::string name, THUINT size)
{
    return (T*) malloc(sizeof(T) * size);
}

template<typename T>
 void THFREE(std::string name,  T*& p)
{
    if(p)
    {
        free(p);
        p = NULL;
    } 
    return;
}


#endif //THMEMORY_H_