/* 
 * Copyright 2012 IS2T. All rights reserved.
 * Modification and distribution is permitted under certain conditions.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
/* 
 * AUTOGENERATED by COMP-ICETEA-CGNU-ARM - 1.0.0 - DO NOT EDIT IT
 */
/* 
 * IceTea to C mapping support. Shall not be directly included by clients.
 */
typedef struct LLLEDS LLLEDS;
#include <stdint.h>
#define LLLEDS_CONCAT0(p,s) p ## s
#define LLLEDS_CONCAT(p,s) LLLEDS_CONCAT0(p,s)
#define LLLEDS_IMPL_initialize LLLEDS_CONCAT(LLLEDS_IMPL,_initialize)
#define LLLEDS_IMPL_getIntensity LLLEDS_CONCAT(LLLEDS_IMPL,_getIntensity__I)
#define LLLEDS_IMPL_setIntensity LLLEDS_CONCAT(LLLEDS_IMPL,_setIntensity__II)
struct LLLEDS
{
	int32_t __icetea__id__;
};
LLLEDS LLLEDS_getSingleton_instance;

/* 
 * Get the unique instance of this type within the system.
 */
LLLEDS* LLLEDS_IMPL_getSingleton(void)
{
	return &LLLEDS_getSingleton_instance;
}
