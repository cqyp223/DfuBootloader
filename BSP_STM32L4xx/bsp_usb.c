/**
  ******************************************************************************
  * @file    bsp_usb.c
  * @author  Benedek Kupper
  * @version 0.1
  * @date    2018-05-21
  * @brief   DfuBootloader BSP for USB communication
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
#include <xpd_pwr.h>
#include <bsp_io.h>
#include <bsp_usb.h>

void BSP_USB_Bind(USB_HandleType *dev)
{
    PWR_vVddUSB(ENABLE);
    GPIO_vInitPin(USB_DM_PIN, USB_DM_CFG);
    GPIO_vInitPin(USB_DP_PIN, USB_DP_CFG);

#ifdef RCC_HSI48_SUPPORT
    USB_vClockConfig(USB_CLOCKSOURCE_HSI48);
#else
    USB_vClockConfig(USB_CLOCKSOURCE_MSI);
#endif
#if defined(USB)
    USB_INST2HANDLE(dev, USB);
#elif defined(USB_OTG_FS)
    USB_INST2HANDLE(dev, USB_OTG_FS);
#endif
}
