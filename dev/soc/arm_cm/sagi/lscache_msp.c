#include "field_manipulate.h"
#include "compile_flag.h"
#include "reg_sysc_cpu.h"

XIP_BANNED void lscache_msp_init()
{
    SYSC_CPU->PD_CPU_CLKG=SYSC_CPU_CLKG_SET_CACHE_MASK;
}

