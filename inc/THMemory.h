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
        void *p;
    } THHEAPMEM;

    class THheapusage
    {
    public:
        THheapusage()
        {
            m_index = 0;
        }
        ~THheapusage()
        {

        }
        int m_index;
        THHEAPMEM pointer[1000];
    public:
        //以后用binary tree do this
        int find(void *p)
        {
        }
        int add(void *p)
        {

        }
        int remove(void* p)
        {

        }
    };

    void TH_HEAPDUMP();
    extern std::map<std::string, std::map<THLLUINT, THHEAPMEM> > g_heap_map;
    extern THheapusage g_default_heap;
}; // namespace THTREENS

#ifdef TH_DEBUG

#define NEW new (std::string(__FILE__), __LINE__)
void *operator new(size_t size) throw(std::bad_alloc);
void *operator new[](size_t size) throw(std::bad_alloc);
void operator delete(void *p) throw();
void operator delete[](void *p) throw();

void *operator new(size_t size, std::string filename, int linenum) throw(std::bad_alloc);
void *operator new[](size_t size, std::string filename, int linenum) throw(std::bad_alloc);
void operator delete(void *p, std::string filename, int linenum);
void operator delete[](void *p, std::string filename, int linenum);

#else

#define NEW new

#endif // TH_DEBUG

#endif //THMEMORY_H_