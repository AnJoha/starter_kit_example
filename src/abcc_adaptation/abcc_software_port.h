/*******************************************************************************
********************************************************************************
**                                                                            **
** ABCC Starter Kit version 390fce4 (2024-10-25)                              **
**                                                                            **
** Delivered with:                                                            **
**    ABP            c799efc (2024-05-14)                                     **
**    ABCC Driver    edc67ee (2024-10-25)                                     **
**                                                                            */
/*******************************************************************************
** Copyright 2013-present HMS Industrial Networks AB.
** Licensed under the MIT License.
********************************************************************************
** File Description:
** Platform dependent macros and functions required by the ABCC driver and
** Anybus objects implementation to be platform independent.
** The description of the macros are found in abcc_port.h. Abcc_port.h is found
** in the public ABCC40 driver interface.
********************************************************************************
*/

#ifndef ABCC_SW_PORT_H_
#define ABCC_SW_PORT_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "abcc_types.h"
#include "abcc_config.h"

#define ABCC_PORT_printf( ... )          printf( __VA_ARGS__ )

#define ABCC_PORT_vprintf( ... )         vprintf( __VA_ARGS__ )

#define ABCC_PORT_UseCritical() ABCC_PORT_UseCriticalImpl()
EXTFUNC void ABCC_PORT_UseCriticalImpl( void );

#define ABCC_PORT_EnterCritical() ABCC_PORT_EnterCriticalImpl()
EXTFUNC void ABCC_PORT_EnterCriticalImpl( void );

#define ABCC_PORT_ExitCritical() ABCC_PORT_ExitCriticalImpl()
EXTFUNC void ABCC_PORT_ExitCriticalImpl( void );

#endif  /* inclusion lock */
