#ifndef _CANYON_COMMAND_COMMAND_DEF
#define _CANYON_COMMAND_COMMAND_DEF
#include "../basic/types.hpp"
namespace canyon{
enum command : uint16_t{  // 指令定义
    sys_quit = 0x0101,  // 退出
    data_mov_i2r = 0x0200,  // 立即数存到寄存器
    data_mov_r2m = 0x0201,  // 寄存器存到内存
    data_mov_m2r = 0x0202,  // 内存存到寄存器
    data_mov_i2m = 0x0203,  // 立即数存到内存
    data_disk_d2m = 0x0204,  // 磁盘（文件）加载到内存
    data_disk_m2d = 0x0205,  // 内存加载到磁盘
    data_disk_i2d = 0x0206,  // 立即数存到磁盘
};}
#endif
