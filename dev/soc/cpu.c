#include "le501x.h"
#include "cpu.h"
#include "section_def.h"
static uint8_t primask_stat;

XIP_BANNED void enter_critical()
{
    primask_stat = __get_PRIMASK();
    __disable_irq();
}

XIP_BANNED void exit_critical()
{
    if(primask_stat == 0)
    {
        __enable_irq();
    }
}

bool in_interrupt()
{
    return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0;
}

