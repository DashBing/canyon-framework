#ifndef _CANYON_CORE
#define _CANYON_CORE
#include "basic/types.hpp"
namespace canyon{
class Core{  // CPU核心类
    /*寄存器定义区*/
    public:
    uint8_t AX[word_length] = {};  // 累加寄存器，用于存放操作数
    uint8_t BX[word_length] = {};  // 基址寄存器，用于地址索引
    uint8_t CX[word_length] = {};  // 
};}
#endif
