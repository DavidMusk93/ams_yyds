//
// Created by Steve on 8/22/2021.
//

#include "macro.h"

// @ref
//  *https://stackoverflow.com/questions/16387745
//    *'b' for u8
//    *'w' for u16
//    *'l' for u32
//    *'q' for u64
//  *https://gcc.gnu.org/onlinedocs/gcc/Constraints.html
//    *simple constraints
//      *'r', a register operand
//      *'I', an immediate integer operand
//      *'0', an operand that matches the specified operand number
//    *constrain modifier
//      *'=', the operand is written to
//      *'+', the operand is both read and written
//  *https://dmalcolm.fedorapeople.org/gcc/2015-08-31/rst-experiment/how-to-use-inline-assembly-language-in-c-code.html#clobbers
//    *clobbers
//      *"cc", indicates that the assembler code modifies the flags register
//  *https://c9x.me/x86/html/file_module_x86_id_273.html
#define __rotate(x,n) ({u32 ret;asm("rorl %1,%0":"=r"(ret):"I"(n),"0"(x):"cc");ret;})

#if TEST_ROTATE
MAIN(){
#define SHIFTBITS 8
    u32 x=0x11223344,y;
    y=(x>>SHIFTBITS)|(x<<(32-SHIFTBITS));
    LOG1("%#x,%#x,%#x",x,y,__rotate(x,SHIFTBITS));
}
#endif