#ifndef _CANYON_CORE
#define _CANYON_CORE
#include "basic/types.hpp"
namespace canyon{
class Core{  // CPU核心类
    /*寄存器定义区*/
    public:
    /*通用寄存器*/
    uint8_t AX[word_length] = {};  // 累加寄存器，用于存放操作数
    uint8_t BX[word_length] = {};  // 基址寄存器，用于地址索引，通常存函数调用第一个参数
    uint8_t CX[word_length] = {};  // 
    uint8_t DX[word_length] = {};
    uint8_t SI[word_length] = {};
    uint8_t DI[word_length] = {};
    uint8_t BP[word_length] = {};
    uint8_t SP[word_length] = {};
};}
#endif
