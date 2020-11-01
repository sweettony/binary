#ifndef THMEMORY_H_
#define THMEMORY_H_

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <cstdlib>
#include <cstring>
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

    typedef struct  tag_heap_info
    {
       void* p;
       int   size;
    }THHEAPINFO;
    
    public:
        THheapusage()
        {
            m_total = 0;
            memset(m_pointer, 0, sizeof(THHEAPINFO) * 1000);
        }
        ~THheapusage()
        {

        }
    private:
        THHEAPINFO m_pointer[1000];
        THLLUINT m_total;
    public:
        int find(void *p)
        {
            for(int i = 0; i < 1000; i++)
            {
                if(m_pointer[i].p == p)
                    return true;
            }
            return false;
        }
        int add(void *p, size_t size)
        {
            for(int i = 0; i < 1000; i++)
            {
                if(m_pointer[i].p == 0)
                {
                    m_pointer[i].p = p;
                    m_pointer[i].size = size;
                    m_total += size;
                    return true;
                }
            }
            return false;
        }
        int remove(void* p)
        {
            for(int i = 0; i < 1000; i++)
            {
                if(m_pointer[i].p == p)
                {
                    m_pointer[i].p = 0;
                    m_total -= m_pointer[i].size;
                    m_pointer[i].size = 0;
                    return true;
                }
            }
            return false;
        }

        int Total_usage(){return m_total;}
        void Dump()
        {
            std::stringstream ss;
            if(m_total / (1024 * 1024) > 0)
            {
                ss << m_total / (1024 * 1024) << "." << m_total % (1024 * 1024) << "MB" << std::endl; 
            }
            else if(m_total / 1024)
            {
                ss << m_total / 1024 << "." << m_total % 1024 << "KB" << std::endl; 
            }
            else
            {
                ss << m_total  << "B" << std::endl; 
            }
            std::cout << ss.str();
            return;
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