/*  hardwareImplementation.h
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  The hardware implementation of the timer, configurable  */


/*
 * Memory addresses
 *
 * PORTx_DATA: Set this to control output, reading will only give what you have output before
 * PORTx_DDR: Set this to control data direction, 1 = output 0 = input
 * PORTx_PINS: Read from this to get input from peripherals
 */
#define PORTB_DATA (*((volatile unsigned char *)0x25))
#define PORTC_DATA (*((volatile unsigned char *)0x28))
#define PORTD_DATA (*((volatile unsigned char *)0x2B))
#define PORTB_DDR (*((volatile unsigned char *)0x24))
#define PORTC_DDR (*((volatile unsigned char *)0x27))
#define PORTD_DDR (*((volatile unsigned char *)0x2A))
#define PORTB_PINS (*((volatile unsigned char *)0x23))
#define PORTC_PINS (*((volatile unsigned char *)0x26))

/*
 * Hardware Pins
 * Used to set output and read input
 * Usage: 
 *
 * DISPLAY_[DATA|DDR|PINS] - The port that the displays are on, used for GPIO
 * DISPLAY_[0-3]_PIN - The respective display's pin
 * SEGMENT_PORT_[DATA|DDR|PINS] - The port that the segments are on, used for GPIO 
 * SEGMENT_[A-G]_PIN - The respective segment's pin
 * MISC_PORT_[DATA|DDR|PINS] - The port that miscellaneous things are on, used for GPIO
 * MISC_[NAME]_PIN - The respective item's pin
 */
#define DISPLAY_DATA PORTB_DATA
#define DISPLAY_DDR PORTB_DDR
#define DISPLAY_PINS PORTB_PINS
#define DISPLAY_0_PIN 0
#define DISPLAY_1_PIN 1
#define DISPLAY_2_PIN 2
#define DISPLAY_3_PIN 3

#define SEGMENT_DATA PORTD_DATA
#define SEGMENT_DDR PORTD_DDR
#define SEGMENT_PINS PORTD_PINS
#define SEGMENT_A_PIN 2
#define SEGMENT_B_PIN 3
#define SEGMENT_C_PIN 4
#define SEGMENT_D_PIN 5
#define SEGMENT_E_PIN 6
#define SEGMENT_F_PIN 7
#define SEGMENT_G_PIN 8
/*
 * Is the last segment on a seperate port? (if not enough pins in one port for all of the segments)
 *
 * 0 = Same port as the rest/Not seperate 1 = Different port/Seperate(port/pin specified later)
 */
#define SEGMENT_G_SEPERATE 1
#define SEPERATE_DATA PORTC_DATA
#define SEPERATE_DDR PORTC_DDR
#define SEPERATE_PINS PORTC_PINS
#define SEPERATE_G_PIN 1

#define MISC_DATA PORTC_DATA
#define MISC_DDR PORTC_DDR
#define MISC_PINS PORTC_PINS
#define MISC_DECIMAL_PIN 0

/*
 * Apply modes(for below function)
 *
 * applyModeClear - Clear the pin
 * applyModeSet - Set the pin to a specified value
 */
#define APPLY_MODE_CLEAR 0
#define APPLY_MODE_SET 1

/*
 * Sets/clears a pin on the specified port in the specified way
 *
 * pinMode: Uses definitions to specify which way to modify the pin on which port
 * ex: SEGMENTDATA
 * applyMode: See above definitions
 * hardwarePin: the pin to clear/set
 */
void HardwareModifyPin(volatile unsigned char portPinMode, int applyMode, int hardwarePin);

/*
 * Initializes the hardware, data directions and such
 *
 * Uses previously defined hardware pins
 */
void HardwareInit();