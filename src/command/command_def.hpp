#ifndef _CANYON_COMMAND_COMMAND_DEF
#define _CANYON_COMMAND_COMMAND_DEF
#include "../basic/types.hpp"
namespace canyon{
enum command : uint16_t{  // 指令定义
    sys_quit = 0x0101,
    data_mov_i2r = 0x0200,
    data_mov_r2m = 0x0201,
    data_mov_m2r = 0x0202,
    data_mov_i2m = 0x0203,
    data_disk_d2m = 0x0204,
    data_disk_m2d = 0x0205,
    data_disk_i2d = 0x0206,
};}
#endif
