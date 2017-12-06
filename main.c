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
#include <Init.h>
#include <Logger.h>
#include <MIDI.h>
#include <Project.h>
#include <UI.h>

int main()
{
    uint8 status;
    
    status = InitializeSystem();
    
    if(status == 0)
    {
        CYASSERT(0);    /* Check for errors in BLE initialization */
    }

    while(1)
    {
        uint16 uiChangeStatus;

        BLE_Run();
        
        uiChangeStatus = UI_Run();
        
        Midi_Run(uiChangeStatus);
        
        if(cyBle_pendingFlashWrite != 0u)
        {
            /* When debug information is sent, store data to device */
            CyBle_StoreBondingData(0u);
        }
    }
}
