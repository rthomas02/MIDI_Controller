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
#ifndef BLE_INTERFACE_H
#define BLE_INTERFACE_H
    
#include <Cytypes.h>    
    

typedef enum
{
    LOW_LATENCY_CONNECTION_PARAMETER_INDEX = 0,
    MEDIUM_LATENCY_CONNECTION_PARAMETER_INDEX,
    TOTAL_NUMBER_OF_CONNECTION_PARAMETERS
} BLE_CONNECTION_PARAM_INDEX;

typedef enum
{
    CONNECTION_PARAMETER_IDLE_STATE,
    CONNECTION_PARAMETER_UPDATE_REQUIRED_STATE,
    CONNECTION_PARAMETER_SENT_STATE,
    CONNECTION_PARAMETER_ACCEPTED_STATE,
    CONNECTION_PARAMETER_REJECTED_STATE,
    CONNECTION_PARAMETER_FAILURE_STATE
} BLE_CONNECTION_PARAM_STATE;


#define CONNECTION_PARAMETER_ACCEPTED                               0x0000
#define CONNECTION_PARAMETER_REJECTED                               0x0001   

uint8 BLE_Start(void);
void BLE_Run(void);
void StackEventHandler(uint32 event, void* eventParam);
static void BLE_StateInit(void);
static void UpdateMidiInterfaceConnParam(BLE_CONNECTION_PARAM_INDEX connectionParamIndex);

#endif  
/* [] END OF FILE */
