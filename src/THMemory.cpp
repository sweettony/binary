#include <iostream>
#include <cstdio>
#include "THMemory.h"
#include <sstream>

using namespace THTREENS;
std::map<std::string, std::map<THLLUINT, THHEAPMEM> > THTREENS::g_heap_map;

#ifdef TH_DEBUG

void* operator new(size_t size, std::string filename, int linenum) throw (std::bad_alloc)
{
    void * p = malloc(size);
    THTREENS::THHEAPMEM node = {filename, linenum, size, p};
    THTREENS::g_heap_map[filename][reinterpret_cast<THLLUINT>(p)] = node;
    return p;
}

void* operator new[](size_t size, std::string filename, int linenum) throw (std::bad_alloc)
{
    
    void * p = malloc(size);
    THTREENS::THHEAPMEM node = {filename, linenum, size, p};
    THTREENS::g_heap_map[filename][reinterpret_cast<THLLUINT>(p)] = node;
    return p;
}


// void  operator delete(void* p) throw()
// {
//     std::cout << "in operator delete " << std::endl;
//     printf("\tpointer = %p\n", p);
//     return free(p);
// }

// void  operator delete[](void* p) throw()
// {
//     std::cout << "in operator delete[] " << std::endl;
//     printf("\tpointer = %p\n", p);
//     return free(p);
// }

void  operator delete(void* p, std::string filename)
{   
    return free(p); 
}

void  operator delete[](void* p, std::string filename)
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




