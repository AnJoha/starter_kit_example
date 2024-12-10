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
** Example of an ADI setup with two simple UINT16 ADIs simulating speed and
** reference speed.
**
** In abcc_driver_config.h make sure that the following definitions are set to:
** ABCC_CFG_STRUCT_DATA_TYPE_ENABLED     0
** ABCC_CFG_ADI_GET_SET_CALLBACK_ENABLED 0
********************************************************************************
*/

#include "application_data_instance_config.h"
#include "abcc.h"

#if (  ABCC_CFG_STRUCT_DATA_TYPE_ENABLED || ABCC_CFG_ADI_GET_SET_CALLBACK_ENABLED )
   #error ABCC_CFG_ADI_GET_SET_CALLBACK_ENABLED must be set to 0 and ABCC_CFG_STRUCT_DATA_TYPE_ENABLED set to 0 in order to run this example
#endif

/*------------------------------------------------------------------------------
** Access descriptor for the ADIs
**------------------------------------------------------------------------------
*/
#define AD_ADI_DESC______  ( 0                            | 0                               | 0                                | 0                         | 0                         )
#define AD_ADI_DESC_____G  ( 0                            | 0                               | 0                                | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC____S_  ( 0                            | 0                               | 0                                | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC____SG  ( 0                            | 0                               | 0                                | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC___W__  ( 0                            | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | 0                         )
#define AD_ADI_DESC___W_G  ( 0                            | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC___WS_  ( 0                            | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC___WSG  ( 0                            | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC__R___  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | 0                         | 0                         )
#define AD_ADI_DESC__R__G  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC__R_S_  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC__R_SG  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC__RW__  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | 0                         )
#define AD_ADI_DESC__RW_G  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC__RWS_  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC__RWSG  ( 0                            | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_N____  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | 0                                | 0                         | 0                         )
#define AD_ADI_DESC_N___G  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | 0                                | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_N__S_  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | 0                                | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC_N__SG  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | 0                                | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_N_W__  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | 0                         )
#define AD_ADI_DESC_N_W_G  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_N_WS_  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC_N_WSG  ( ABP_APPD_DESCR_NVS_PARAMETER | 0                               | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_NR___  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | 0                         | 0                         )
#define AD_ADI_DESC_NR__G  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_NR_S_  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC_NR_SG  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | 0                                | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_NRW__  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | 0                         )
#define AD_ADI_DESC_NRW_G  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | 0                         | ABP_APPD_DESCR_GET_ACCESS )
#define AD_ADI_DESC_NRWS_  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | 0                         )
#define AD_ADI_DESC_NRWSG  ( ABP_APPD_DESCR_NVS_PARAMETER | ABP_APPD_DESCR_MAPPABLE_READ_PD | ABP_APPD_DESCR_MAPPABLE_WRITE_PD | ABP_APPD_DESCR_SET_ACCESS | ABP_APPD_DESCR_GET_ACCESS )


/*------------------------------------------------------------------------------
** Data holder for the ADI instances
**------------------------------------------------------------------------------
*/
static UINT16 appl_iSpeed;
static UINT16 appl_iRefSpeed;

/*------------------------------------------------------------------------------
** Min, max and default value for appl_aiUint16
**------------------------------------------------------------------------------
*/
static AD_UINT16Type appl_sUint16Prop = { { 0, 0xFFFF, 0 } };

/*-------------------------------------------------------------------------------------------------------------
** 1. iInstance | 2. pabName | 3. bDataType | 4. bNumOfElements | 5. bDesc | 6. pxValuePtr | 7. pxValuePropPtr
**--------------------------------------------------------------------------------------------------------------
*/
const AD_AdiEntryType APPL_asAdiEntryList[] =
{
   {  0x1,  "SPEED",     ABP_UINT16,   1, AD_ADI_DESC___W_G, { { &appl_iSpeed,    &appl_sUint16Prop } } },
   {  0x2,  "REF_SPEED", ABP_UINT16,   1, AD_ADI_DESC__R_S_, { { &appl_iRefSpeed, &appl_sUint16Prop } } }
};

/*------------------------------------------------------------------------------
** Map all adi:s in both directions
**------------------------------------------------------------------------------
** 1. AD instance | 2. Direction | 3. Num elements | 4. Start index |
**------------------------------------------------------------------------------
*/
const AD_MapType APPL_asAdObjDefaultMap[] =
{
   { 1, PD_WRITE, AD_MAP_ALL_ELEM, 0 },
   { 2, PD_READ,  AD_MAP_ALL_ELEM, 0 },
   { AD_MAP_END_ENTRY }
};

UINT16 APPL_GetNumAdi( void )
{
   return( sizeof( APPL_asAdiEntryList ) / sizeof( AD_AdiEntryType ) );
}

void APPL_CyclicalProcessing()
{
	return;
}
