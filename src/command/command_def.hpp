#ifndef _CANYON_COMMAND_COMMAND_DEF
#define _CANYON_COMMAND_COMMAND_DEF
#include "../basic/types.hpp"
namespace canyon{
enum command : uint16_t{  // 指令定义
    sys_quit = 0x0101,  // 退出
    sys_io_o_i = 0x0102,
    sys_io_o_r = 0x0103,
    sys_io_o_m = 0x0104,
    sys_io_i_r = 0x0105,
    sys_io_i_m = 0x0106,
    data_mov_i2r = 0x0107,  // 立即数存到寄存器
    data_mov_r2m = 0x0108,  // 寄存器存到内存
    data_mov_m2r = 0x0109,  // 内存存到寄存器
    data_mov_i2m = 0x010a,  // 立即数存到内存
    data_disk_d2m = 0x010b,  // 磁盘（文件）加载到内存
    data_disk_m2d = 0x010c,  // 内存加载到磁盘
    data_disk_i2d = 0x010d,  // 立即数存到磁盘
    jmp_i = 0x010e,
    jmp_i_if_r = 0x010f,
    jmp_i_ifn_r = 0x0110,
    jmp_i_if_ifn_r = 0x0111,
    jmp_ic = 0x0112,
    jmp_ic_if_r = 0x0113,
    jmp_ic_ifn_r = 0x0114,
    jmp_ic_if_ifn_r = 0x0115,
    jmp_r = 0x0116,
    jmp_r_if_r = 0x0117,
    jmp_r_ifn_r = 0x0118,
    jmp_r_if_ifn_r = 0x0119,

    alu_eq = 0x0200,
    alu_or = 0x0201,
    alu_and = 0x0202,
    alu_not = 0x0203,
    alu_xor = 0x0204,
    alu_int_big = 0x0205,
    alu_int_big_eq = 0x0206,
    alu_int_small = 0x0207,
    alu_int_small_eq = 0x0208,
    alu_int_plus = 0x0209,
    alu_int_sub = 0x020a,
    alu_int_times = 0x020b,
    alu_int_div = 0x020c,
};}
#endif
