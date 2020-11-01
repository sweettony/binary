#include <iostream>
#include <cstdio>
#include "THMemory.h"
#include <sstream>
#include <list>


using namespace THTREENS;
std::map<std::string, std::map<THLLUINT, THHEAPMEM> > THTREENS::g_heap_map;
THTREENS::THheapusage THTREENS::g_default_heap;

#ifdef TH_DEBUG

static void THRemove_pointer_of_map(void* p)
{
    std::map<std::string, std::map<THLLUINT, THHEAPMEM> >::iterator it = g_heap_map.begin();
    for(; it != g_heap_map.end(); it++)
    {
        if(it->second.find(reinterpret_cast<THLLUINT>(p)) != it->second.end())
        {
            it->second.erase(it->second.find(reinterpret_cast<THLLUINT>(p)));
            if(it->second.size() == 0)
            {
                g_heap_map.erase(it);
                break;
            }
        }
    }
    return;
}

void* operator new(size_t size) throw(std::bad_alloc)
{  
   void * p = malloc(size); 
   THTREENS::g_default_heap.add(p);
   return p;
}

void* operator new[](size_t size) throw(std::bad_alloc)
{
   void * p = malloc(size);
   THTREENS::g_default_heap.add(p);
   return p;
}


void  operator delete(void* p) throw()
{
    THTREENS::g_default_heap.remove(p);
    THRemove_pointer_of_map(p);
    return free(p);
}

void  operator delete[](void* p) throw()
{
    THTREENS::g_default_heap.remove(p);
    THRemove_pointer_of_map(p);
    return free(p);
}


void* operator new(size_t size, std::string filename, int linenum) throw (std::bad_alloc)
{
   // std::cout << "in usr defined new" << std::endl;
    void * p = malloc(size);
    THTREENS::THHEAPMEM node = {filename, linenum, size, p};
    THTREENS::g_heap_map[filename][reinterpret_cast<THLLUINT>(p)] = node;
    return p;
}

void* operator new[](size_t size, std::string filename, int linenum) throw (std::bad_alloc)
{
   // std::cout << "in usr defined new[]" << std::endl;
    void * p = malloc(size);
    THTREENS::THHEAPMEM node = {filename, linenum, size, p};
    THTREENS::g_heap_map[filename][reinterpret_cast<THLLUINT>(p)] = node;
    return p;
}

void  operator delete(void* p, std::string filename, int linenum)
{   
    return free(p); 
}

void  operator delete[](void* p, std::string filename, int linenum)
{
    return free(p);    
}

#endif

void THTREENS::TH_HEAPDUMP()
{
    std::map<std::string,  std::map<THLLUINT, THHEAPMEM> >::iterator it =  g_heap_map.begin();
    std::cout << "Heap Resource Usage" << std::endl;
    std::map<THLLUINT, THHEAPMEM>::iterator inner_it;
    std::stringstream ss;
    for(; it != g_heap_map.end(); it++)
    {
        std::cout << "filename = " << it->first << std::endl;
        inner_it = it->second.begin();
        for(; inner_it != it->second.end(); inner_it++)
        {
            ss << "\t" << "<" 
               << "linenum = " << inner_it->second.line << ", " 
               << "size = " << inner_it->second.size << ", "
               << "addr = " << inner_it->second.p    << ">" 
               <<std::endl;
            std::cout << ss.str();
        }
    }
}




