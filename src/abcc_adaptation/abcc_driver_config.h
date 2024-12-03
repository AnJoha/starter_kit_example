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
** Copyright 2015-present HMS Industrial Networks AB.
** Licensed under the MIT License.
********************************************************************************
** File Description:
** User configuration of the ABCC driver. The configuration parameters are
** documented in the driver's public interface abcc_config.h.
**
** Configuration options with default values defined in abcc_config.h will be
** used unless overriden here.
********************************************************************************
*/

#ifndef ABCC_DRV_CFG_H_
#define ABCC_DRV_CFG_H_

#include "abcc_types.h"
#include "abp.h"

/*------------------------------------------------------------------------------
** All interface drivers are supported.
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_DRV_PARALLEL_ENABLED              1
#define ABCC_CFG_DRV_SPI_ENABLED                   1
#define ABCC_CFG_DRV_SERIAL_ENABLED                1

/*------------------------------------------------------------------------------
** The software can both get the operating mode from external resource and set
** the selected operating mode to the ABCC host connector.
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_OP_MODE_GETTABLE                  1
#define ABCC_CFG_OP_MODE_SETTABLE                  1

/*------------------------------------------------------------------------------
** ABCC memory access configuration for parallel operating modes
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_MEMORY_MAPPED_ACCESS_ENABLED      0

/*------------------------------------------------------------------------------
** Module identification configuration
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_MODULE_ID_PINS_CONN               1

/*------------------------------------------------------------------------------
** Module detection configuration
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_MOD_DETECT_PINS_CONN              1

/*------------------------------------------------------------------------------
** Configuration of message handling
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_MAX_NUM_APPL_CMDS                 ( 4 )
#define ABCC_CFG_MAX_NUM_ABCC_CMDS                 ( 4 )
#define ABCC_CFG_MAX_PROCESS_DATA_SIZE             ( 4096 )

/*------------------------------------------------------------------------------
** Interrupt configuration excluding sync
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_POLL_ABCC_IRQ_PIN_ENABLED         1
#define ABCC_CFG_INT_ENABLED                       0

#if( ABCC_CFG_INT_ENABLED )
   #define ABCC_CFG_INT_ENABLE_MASK_PAR            ( ABP_INTMASK_RDPDIEN | ABP_INTMASK_STATUSIEN | ABP_INTMASK_RDMSGIEN | ABP_INTMASK_WRMSGIEN | ABP_INTMASK_ANBRIEN  )
   #define ABCC_CFG_INT_ENABLE_MASK_SPI            ( 0 )
   #define ABCC_CFG_HANDLE_INT_IN_ISR_MASK         ( ABP_INTMASK_RDPDIEN )
#endif

/*------------------------------------------------------------------------------
** Assume firmware update on initial communication timeout.
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_DRV_ASSUME_FW_UPDATE_ENABLED      1

/*------------------------------------------------------------------------------
** Debug and error macro configuration
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_ERR_REPORTING_ENABLED             1
#define ABCC_CFG_DEBUG_LOG_COLORS_ENABLED          1
#define ABCC_CFG_DEBUG_TIMESTAMPS_ENABLED          1
#define ABCC_CFG_DEBUG_EVENT_ENABLED               1
#define ABCC_CFG_DEBUG_ERR_ENABLED                 1

#define TP_ERROR_STRINGS                           1

#endif  /* inclusion lock */
