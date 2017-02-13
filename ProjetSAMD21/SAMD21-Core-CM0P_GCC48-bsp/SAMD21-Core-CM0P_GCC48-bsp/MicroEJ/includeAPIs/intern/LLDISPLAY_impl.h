/* 
 * Copyright 2011-2016 IS2T. All rights reserved.
 * Modification and distribution is permitted under certain conditions.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
/* 
 * AUTOGENERATED by COMP-ICETEA-CGNU-ARM - 1.0.0 - DO NOT EDIT IT
 */
/* 
 * IceTea to C mapping support. Shall not be directly included by clients.
 */
#include <stdint.h>
#define LLDISPLAY_CONCAT0(p,s) p ## s
#define LLDISPLAY_CONCAT(p,s) LLDISPLAY_CONCAT0(p,s)
#define LLDISPLAY_IMPL_initialize LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_initialize)
#define LLDISPLAY_IMPL_getWidth LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_getWidth)
#define LLDISPLAY_IMPL_getHeight LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_getHeight)
#define LLDISPLAY_IMPL_getGraphicsBufferAddress LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_getGraphicsBufferAddress)
#define LLDISPLAY_IMPL_getWorkingBufferStartAddress LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_getWorkingBufferStartAddress)
#define LLDISPLAY_IMPL_getWorkingBufferEndAddress LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_getWorkingBufferEndAddress)
#define LLDISPLAY_IMPL_flush LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_flush__IIIII)
#define LLDISPLAY_IMPL_synchronize LLDISPLAY_CONCAT(LLDISPLAY_IMPL,_synchronize)
LLDISPLAY LLDISPLAY_getSingleton_instance;

/* 
 * Get the unique instance of this type within the system.
 */
LLDISPLAY* LLDISPLAY_IMPL_getSingleton(void)
{
	return &LLDISPLAY_getSingleton_instance;
}
