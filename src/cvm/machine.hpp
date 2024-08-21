#ifndef _CANYON_MACHINE
#define _CANYON_MACHINE
#include "basic/types.hpp"
#include "core.hpp"
namespace canyon{
/*
虚拟机开机任务：

将文件信息存为列表
把本虚拟机的this指针分发给各核
初始化内存
将ROM（第一个文件）load到内存位置
启动启动核，让启动核从加载位置开始执行
...
退出并销毁
*/
class Machine{  // 虚拟机类
    public:
    Machine(uint64_t core_count=1, uint64_t memory_size=default_memory_size);
};}
#endif
