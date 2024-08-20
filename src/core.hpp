#ifndef _CANYON_CORE
#define _CANYON_CORE
#include "basic/types.hpp"
namespace canyon{
/*
启动核任务：

从接口取到执行地址和虚拟机this指针
在接口处循环调用parser解码运行指令，传core的this指针，并且告知权限级别
...
遇到退出时关闭核/遇到关机时通知内核保存工作，没有内核直接通知所有核保存当下并退出/遇到强制断电就迅速停止程序
*/
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
