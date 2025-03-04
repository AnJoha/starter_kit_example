/*******************************************************************************
********************************************************************************
**                                                                            **
** ABCC Starter Kit version 003e7c1 (2024-11-29)                              **
**                                                                            **
** Delivered with:                                                            **
**    ABP            c799efc (2024-05-14)                                     **
**    ABCC Driver    0401fde (2024-11-13)                                     **
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
#define ABCC_CFG_MESSAGE_SIZE_CHECK_ENABLED      1

#define ANB_FSI_OBJ_ENABLE 1
#define APP_IA_SER_NUM_ENABLE 1
#define APP_IA_SER_NUM_VALUE 0x12345678

/*------------------------------------------------------------------------------
** Debug level configuration
**
** Configures the level of debug logging.
**
** One of:
** ABCC_LOG_SEVERITY_FATAL_ENABLED
** ABCC_LOG_SEVERITY_ERROR_ENABLED
** ABCC_LOG_SEVERITY_WARNING_ENABLED
** ABCC_LOG_SEVERITY_INFO_ENABLED
** ABCC_LOG_SEVERITY_DEBUG_ENABLED
**------------------------------------------------------------------------------
*/
#define ABCC_CFG_LOG_SEVERITY ABCC_LOG_SEVERITY_INFO_ENABLED
#define ABCC_CFG_LOG_FILE_LINE_ENABLED 1
#define ABCC_CFG_LOG_TIMESTAMPS_ENABLED 1
#define ABCC_CFG_LOG_STRINGS_ENABLED 1
#define ABCC_CFG_LOG_COLORS_ENABLED 1
#define ABCC_CFG_DEBUG_CMD_SEQ_ENABLED 1
#define ABCC_CFG_DEBUG_MESSAGING_ENABLED 1
#define ABCC_CFG_DEBUG_HEXDUMP_SPI_ENABLED 0
#define ABCC_CFG_DEBUG_HEXDUMP_UART_ENABLED 0

#define APPL_SELECT_FIRMWARE_DEBUG_ENABLED 1


#define ABCC_CFG_COMMAND_RESPONSE_LIST \
   ABCC_APPLICATION_OBJ_SERIAL_NR_GET_VALUE(0x5555), \
   ABCC_APPLICATION_OBJ_PRODUCT_NAME_GET_VALUE("Liquid pumper 9000"), \
   ABCC_APPLICATION_OBJ_VENDOR_NAME_GET_CBFUNC, \
   ABCC_ETHERNETIP_OBJ_VENDOR_ID_GET_CBFUNC, \
   ABCC_ETHERNETIP_OBJ_DEVICE_TYPE_GET_CBFUNC, \
   ABCC_ETHERNETIP_OBJ_PRODUCT_CODE_GET_CBFUNC, \
   ABCC_PROFINET_OBJ_DEVICE_ID_GET_CBFUNC, \
   ABCC_PROFINET_OBJ_VENDOR_ID_GET_CBFUNC, \
   ABCC_PROFINET_OBJ_ORDER_ID_GET_CBFUNC, \
   ABCC_APPLICATION_OBJ_FW_AVAILABLE_GET_CBFUNC, \
   ABCC_APPLICATION_OBJ_FW_AVAILABLE_SET_CBFUNC

#define ABCC_CFG_OBJ_COMMAND_RESPONSE_LIST  \
   ABCC_APPLICATION_OBJ_OA_NAME_GET_VALUE("Application"), \
   ABCC_APPLICATION_OBJ_OA_REV_GET_VALUE(0x02), \
   ABCC_APPLICATION_OBJ_OA_NR_INST_GET_VALUE(0x0001), \
   ABCC_APPLICATION_OBJ_OA_HI_INST_NR_GET_VALUE(0x0001), \
   ABCC_APPLICATION_OBJ_OA_RESET_CBFUNC


#endif  /* inclusion lock */
