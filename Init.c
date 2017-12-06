/* ========================================
 *
 * Copyright Reba Thomas & Rishamdeep Khehra 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <BLE_Interface.h>
#include <Configuration.h>
#include <Logger.h>
#include <Project.h>
#include <UI.h>

uint8 InitializeSystem(void)
{
    uint8 apiReturn = 1;

    CyGlobalIntEnable;

    PWM_Start();

    UI_Start();
    
    Midi_Start();

    apiReturn = BLE_Start();
    
#if LOGGING_ENABLED
    Logger_Start();
#endif
    
    return apiReturn;
}
/* [] END OF FILE */
