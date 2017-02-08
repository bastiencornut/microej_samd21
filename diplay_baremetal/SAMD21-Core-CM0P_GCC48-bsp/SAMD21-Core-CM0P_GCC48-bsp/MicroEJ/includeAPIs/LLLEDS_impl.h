/* 
 * Copyright 2012 IS2T. All rights reserved.
 * Modification and distribution is permitted under certain conditions.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
/* 
 * AUTOGENERATED by COMP-ICETEA-CGNU-ARM - 1.0.0 - DO NOT EDIT IT
 */
/* 
 * Implementation header file. Shall only be included by client implementation C files.
 */
#include <stdint.h>
#include <intern/LLLEDS_impl.h>
// --------------------------------------------------------------------------------
// -                                  Constants                                   -
// --------------------------------------------------------------------------------

/**
 * Intensity value to turn off a LED.  
 */
#define LLLEDS_MIN_INTENSITY (0)

/**
 * Maximum intensity that a LED can handle. If a LED does not handle intensity, any 
 * valid intensity different from {@link LLLEDS_MIN_INTENSITY} turns the LED on.
 */
#define LLLEDS_MAX_INTENSITY (255)

// --------------------------------------------------------------------------------
// -                      Functions that must be implemented                      -
// --------------------------------------------------------------------------------

/**
 * Initializes the LEDs.
 * @return the number of LEDs in the group.
 */
int32_t LLLEDS_IMPL_initialize(void);

/**
 * Get the intensity of the LED.
 * @return the intensity of the LED
 */
int32_t LLLEDS_IMPL_getIntensity(int32_t ledID);

/**
 * Set the intensity of the LED.
 * A 0 intensity turns off the LED, intensity of 255 turns on the LED to max power.
 * @param intensity the intensity of the LED
 */
void LLLEDS_IMPL_setIntensity(int32_t ledID, int32_t intensity);
