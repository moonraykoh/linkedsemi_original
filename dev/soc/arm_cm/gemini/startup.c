#include "gemini.h"
#include "common.h"
extern uint32_t __StackTop;
#define NMI_Handler Default_Handler
#define HardFault_Handler Default_Handler
#define MemManage_Handler Default_Handler
#define BusFault_Handler Default_Handler
#define UsageFault_Handler Default_Handler
#define PendSV_Handler Default_Handler
#define DebugMon_Handler Default_Handler
void Default_Handler(){while(1);}
void SystemInit(void);
void _start(void) __attribute__ ((noreturn));
extern uint32_t __data_lma__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;

__attribute__ ((naked)) void Reset_Handler()
{
    SystemInit();
    uint32_t *src = &__data_lma__;
    uint32_t *start = &__data_start__;
    uint32_t *end = &__data_end__;
    memcpy32(start,src,end-start);
    _start();
}

extern uint32_t __StackTop;
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

__VECTOR_TABLE_ATTRIBUTE void const * const __isr_vector[IRQn_Max + 16]={
&__StackTop        ,
Reset_Handler      ,
NMI_Handler        ,
HardFault_Handler  ,
MemManage_Handler  ,
BusFault_Handler   ,
UsageFault_Handler ,
0                  ,
0                  ,
0                  ,
0                  ,
SVC_Handler        ,
DebugMon_Handler   ,
0                  ,
PendSV_Handler     ,
SysTick_Handler    ,
};
