#ifndef THMEMORY_H_
#define THMEMORY_H_

#include <string>
#include <map>
#include <cstdlib>
#include <new>
#include "THStatVal.h"

namespace THTREENS
{
    typedef struct tag_th_heap_memory
    {
        std::string name;
        int line;
        THLLUINT size;
        void* p;
    }THHEAPMEM;
    extern std::map<std::string, std::map<THLLUINT, THHEAPMEM> > g_heap_map;

    void TH_HEAPDUMP();
};

#ifdef TH_DEBUG

#define NEW new(std::string(__FILE__), __LINE__)
//#define NEW(str) new(std::string(str), __LINE__) // do not allow overloading on macro
#define DELETE(p, str)  ::operator delete(p, std::string(str))
#define DELETE_(p, str) ::operator delete[](p, std::string(str))

void* operator new(size_t size, std::string filename, int linenum) throw (std::bad_alloc);
void* operator new[](size_t size, std::string filename, int linenum) throw (std::bad_alloc);
void  operator delete(void* p, std::string filename);
void  operator delete[](void* p, std::string filename);

#else

#define NEW new
#define NEW(str) new
#define DELETE(p, str) delete p
#define DELETE_[](p, str) delete[] p

#endif // TH_DEBUG


#endif //THMEMORY_H_