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
#ifndef _LLDISPLAY_intern
#define _LLDISPLAY_intern 
typedef struct LLDISPLAY LLDISPLAY;
#include <stdint.h>
#ifdef __cplusplus
	extern "C" {
#endif
#define LLDISPLAY_initialize __icetea__virtual__com_is2t_display_backend_AbstractDisplay___initialize
#define LLDISPLAY_getWidth __icetea__virtual__com_is2t_display_backend_AbstractDisplay___getWidth
#define LLDISPLAY_getHeight __icetea__virtual__com_is2t_display_backend_AbstractDisplay___getHeight
#define LLDISPLAY_getGraphicsBufferAddress __icetea__virtual__com_is2t_display_backend_AbstractDisplay___getGraphicsBufferAddress
#define LLDISPLAY_getWorkingBufferStartAddress __icetea__virtual__com_is2t_display_backend_AbstractDisplay___getWorkingBufferStartAddress
#define LLDISPLAY_getWorkingBufferEndAddress __icetea__virtual__com_is2t_display_backend_AbstractDisplay___getWorkingBufferEndAddress
#define LLDISPLAY_flush __icetea__virtual__com_is2t_display_backend_AbstractDisplay___flush__IIIII
#define LLDISPLAY_synchronize __icetea__virtual__com_is2t_display_backend_AbstractDisplay___synchronize
struct LLDISPLAY
{
	int32_t __icetea__id__;
};
#ifdef __cplusplus
	}
#endif
#endif
