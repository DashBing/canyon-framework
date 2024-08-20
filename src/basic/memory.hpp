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
    void add_page(uint8_t * adr, word_length_t size_byte){  // 添加已有内存页
        memlist.push_back(adr);
        if(memindex.size() == 0)memindex.push_back(size_byte-1);
        else memindex.push_back(memindex.back()+size_byte);
    }
    void create_page(word_length_t size_byte){  // 创建内存页
        add_page(new uint8_t[size_byte], size_byte);
    }
    uint8_t & at(word_length_t index){  // 索引位置
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
    void clear(){  // 清空所有
        for(auto i : memlist){
            delete[] i;
        }
        memlist.clear();
        memindex.clear();
    }
    word_length_t get_page_size(){  // 取页数
        return(memlist.size());
    }
    word_length_t size(){  // 取总大小
        if(memindex.size()==0)return 0;
        else return(memindex.back());
    }
    word_length_t check_page_size(word_length_t index){  // 查看一个页的大小
        if(index>memindex.size()-1)return(0);
        else if(index==0)return(memindex[0]);
        else return(memindex[index]-memindex[index-1]);
    }
    void remove_page(word_length_t index){  // 从表中移除页
        if(index>memindex.size()-1)return;
        word_length_t size = memindex.size()-1;
        word_length_t l = memindex[index];

        memlist.erase(memlist.begin()+index);
        memindex.erase(memindex.begin()+index);
        if(index==size)return;
        for(int i = index; i<memindex.size(); i++){
            memindex[i] -= l;
        }
    }
    void delete_page(word_length_t index){
        if(index>memindex.size()-1)return;
        delete[] memlist[index];
        remove_page(index);
    }

    public:
    Memory(){}
    Memory(word_length_t size_byte){create_page(size_byte);}
    ~Memory(){clear();}

    public:
    uint8_t & operator [](word_length_t index){return(at(index));}
};
}
#endif
