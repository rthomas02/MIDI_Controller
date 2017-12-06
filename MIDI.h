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
#ifndef MIDI_H
#define MIDI_H    

#include <Cytypes.h>
#include <Project.h>    
    
/* MIDI Constants**/      
#define MAX_NUMBER_OF_MIDI_PACKETS                  (10u)
#define MAX_MIDI_PACKET_LENGTH                      (4u)
#define MIDI_PACKET_HEADER                          (0x80) 
#define MIDI_NOTE_ON_CHANNEL_0                      (0x90)
    
#define MIDI_NOTE_VELOCITY_OFF                      (0x00)
#define MIDI_NOTE_VELOCITY_ON                       (0x7F)    
    
#define LOW                                         (0u)
#define HIGH                                        (1u)    
    
/* MIDI enums*/      
typedef enum
{
    MIDI_PACKET_INVALID,
    MIDI_PACKET_VALID
} MIDI_PACKET_STATUS;
   
/* MIDI Data Structures*/    
typedef struct
{
    uint8 midiNotificationPacket[CYBLE_GATT_MTU];
    uint8 dataIndex;
    MIDI_PACKET_STATUS packetStatus;
} MIDI_PACKET;

typedef struct
{
    MIDI_PACKET midiPacket[MAX_NUMBER_OF_MIDI_PACKETS];
    uint8 packetIndex;
} MIDI_BUFFER;

/*Function Prototypes*/
void Midi_Start(void);
void MIDIEventHandler(uint32 event, void* eventParam);
void Midi_Run(uint16 uiChangeStatus);
uint8 IsMidiEnabled(void);
void ServiceMidiOutData(void);

static void Midi_GenerateMessages(uint16 uiChangeStatus);
static uint8 Midi_GetTimeStamp(uint8 byteNumber);
static void Midi_UpdateBufferPointers(void);
static void Midi_TransferMessages(void);

#endif
/* [] END OF FILE */
