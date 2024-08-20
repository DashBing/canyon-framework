#ifndef _CANYON_BASIC_MEMORY
#define _CANYON_BASIC_MEMORY

#include "types.hpp"
#include <vector>
#include <stdexcept>

namespace canyon{

namespace memory_priv{
    void throw_out_of_range(){
        throw std::out_of_range("Memory index exceeds memory size.");
    }
}

class Memory{
    protected:
    std::vector<uint8_t *> memlist;
    std::vector<word_length_t> memindex;

    public:
    void add_memory_block(word_length_t size_byte){
        memlist.push_back(new uint8_t[size_byte]);
        if(memindex.size() == 0)memindex.push_back(size_byte-1);
        else memindex.push_back(memindex.back()+size_byte);
    }
    uint8_t & at(word_length_t index){
        bool found = false;
        uint8_t *c;
        if(memindex.size()==0)memory_priv::throw_out_of_range();
        else if(0<=index&&index<=memindex[0]){
            found = true;
            c = memlist[0]+index;
        }
        else if(memindex.size()>1)for(word_length_t i=1; i<memindex.size(); i++){
            if(memindex[i-1]<index&&index<=memindex[i]){
                found = true;
                c = memlist[i]+index-memindex[i-1];
            }
        }
        if(!found)memory_priv::throw_out_of_range();
        if(found){
            uint8_t &p = *c;
            return(p);
        }
        else memory_priv::throw_out_of_range();
    }
    void clear(){
        for(auto i : memlist){
            delete[] i;
        }
        memlist.clear();
        memindex.clear();
    }

    public:
    Memory(){}
    Memory(word_length_t size_byte){add_memory_block(size_byte);}
    ~Memory(){clear();}

    public:
    uint8_t & operator [](word_length_t index){return(at(index));}
};
}
#endif
