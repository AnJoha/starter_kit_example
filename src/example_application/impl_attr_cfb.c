#include "abcc_host_attributes_lookup.h"

/*------------------------------------------------------------------------------
** Callback functions used by attribute table.
** **------------------------------------------------------------------------------
*/
UINT32 ABCC_ImplApplicationObjSerialNum_Get(void)
{
    return( 0xFF000001 );
}

UINT16 ABCC_ImplApplicationObjVendortName_Get( char* pPackedStrDest, UINT16 iBuffSize )
{
   static const char* my_product_name = "My dynamic vendor name";
   UINT16 iStrLength = (UINT16)strlen(my_product_name);

   iStrLength = iStrLength > iBuffSize ? iBuffSize : iStrLength;
   memcpy( pPackedStrDest, my_product_name, iStrLength );
   return( iStrLength );
}

UINT16 ABCC_ImplApplicationObjProductName_Get( char* pPackedStrDest, UINT16 iBuffSize )
{
   static const char* my_product_name = "My dynamic product name";
   UINT16 iStrLength = (UINT16)strlen(my_product_name);

   iStrLength = iStrLength > iBuffSize ? iBuffSize : iStrLength;
   memcpy( pPackedStrDest, my_product_name, iStrLength );
   return( iStrLength );
}

void ABCC_ImplApplicationObjFirmwareAvailable_Set( UINT8 bValue )
{
    /* Store FW flag in NVS. */
    ABCC_LOG_INFO( "Candidate FW flag: %u\n", bValue );
}

UINT8 ABCC_ImplApplicationObjFirmwareAvailable_Get( void )
{
   /* Return FW flag from NVS. */
   return( 0 );
}





UINT16 ABCC_ImplEthernetIpObjVendorId_Get( void )
{
   return( 1133 );
}

UINT16 ABCC_ImplEthernetIpObjDeviceType_Get( void )
{
   return( 6655 );
}

UINT16 ABCC_ImplEthernetIpObjProductCode_Get( void )
{
   return( 911 );
}






UINT16 ABCC_ImplProfinetIoObjDeviceId_Get( void )
{
   return( 0xBEEF );
}

UINT16 ABCC_ImplProfinetIoObjVendorId_Get( void )
{
   return( 0xDEAD );
}

UINT16 ABCC_ImplProfinetIoObjOrderId_Get( char* pPackedStrDest, UINT16 iBuffSize )
{
   static const char* my_product_name = "My dynamic OrderId";
   UINT16 iStrLength = (UINT16)strlen(my_product_name);

   iStrLength = iStrLength > iBuffSize ? iBuffSize : iStrLength;
   memcpy( pPackedStrDest, my_product_name, iStrLength );
   return( iStrLength );
}
