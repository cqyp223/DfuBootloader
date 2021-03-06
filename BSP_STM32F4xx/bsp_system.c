/**
  ******************************************************************************
  * @file    bsp_system.c
  * @author  Benedek Kupper
  * @version 0.1
  * @date    2018-05-21
  * @brief   DfuBootloader BSP for system clocking
  *
  * Copyright (c) 2018 Benedek Kupper
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *     http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  */
#include <bsp_system.h>
#include <xpd_rcc.h>

static const RCC_PLL_InitType pllconf = {
    .State = ENABLE,
    .Source = HSE,
    .M = HSE_VALUE_Hz / 1000000,
    .N = 336,
    .P = 4,         /* 1 * 336 / 4 = PLLP =  84000000 -> SYSCLK */
    .Q = 7          /* 1 * 336 / 7 = PLLQ =  48000000 -> USB */
};

/* System clocks configuration */
void SystemClock_Config(void)
{
    RCC_eHSE_Config(OSC_ON);
    RCC_ePLL_Config(&pllconf);

    /* System clocks configuration */
    RCC_eHCLK_Config(PLL, CLK_DIV1, 3);

    RCC_vPCLK1_Config(CLK_DIV2);
    RCC_vPCLK2_Config(CLK_DIV1);
}
