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
#ifndef UI_H
#define UI_H
    
#include <MIDI.h>
    
/*UI Enums*/
typedef enum
{
    UI_IDLE_STATE,
    UI_SCANNING_STATE,
    UI_RESULT_STATE
} UI_STATE;

/* UI Constants*/
#define NO_FINGER_ON_SLIDER                         0xFFFF
#define NO_UI_STATE_CHANGE                          0xFFFE
#define MAX_SLIDER_CENTROID                         (100u)

#define IsUIEnabled()                               IsMidiEnabled()

/* Function Prototypes*/
void UI_Start(void);
uint16 UI_Run(void);
    
#endif
/* [] END OF FILE */
