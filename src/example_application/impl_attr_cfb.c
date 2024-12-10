#include "abcc_host_attributes_lookup.h"





/*------------------------------------------------------------------------------
** Callback functions used by attribute table.
** **------------------------------------------------------------------------------
*/
UINT32 ABCC_ImplApplicationObjSerialNum(void)
{
    return( 0xFF000001 );
}

UINT16 ABCC_ImplApplicationObjVendortName( char* pPackedStrDest, UINT16 iBuffSize )
{
   static const char* my_product_name = "My dynamic vendor name";
   UINT16 iStrLength = (UINT16)strlen(my_product_name);

   iStrLength = iStrLength > iBuffSize ? iBuffSize : iStrLength;
   memcpy( pPackedStrDest, my_product_name, iStrLength );
   return( iStrLength );
}

UINT16 ABCC_ImplApplicationObjProductName( char* pPackedStrDest, UINT16 iBuffSize )
{
   static const char* my_product_name = "My dynamic product name";
   UINT16 iStrLength = (UINT16)strlen(my_product_name);

   iStrLength = iStrLength > iBuffSize ? iBuffSize : iStrLength;
   memcpy( pPackedStrDest, my_product_name, iStrLength );
   return( iStrLength );
}






UINT16 ABCC_ImplEthernetIpObjVendorId( void )
{
   return( 1133 );
}

UINT16 ABCC_ImplEthernetIpObjDeviceType( void )
{
   return( 6655 );
}

UINT16 ABCC_ImplEthernetIpObjProductCode( void )
{
   return( 911 );
}






UINT16 ABCC_ImplProfinetIoObjDeviceId( void )
{
   return( 0xBEEF );
}

UINT16 ABCC_ImplProfinetIoObjVendorId( void )
{
   return( 0xDEAD );
}

UINT16 ABCC_ImplProfinetIoObjOrderId( char* pPackedStrDest, UINT16 iBuffSize )
{
   static const char* my_product_name = "My dynamic OrderId";
   UINT16 iStrLength = (UINT16)strlen(my_product_name);

   iStrLength = iStrLength > iBuffSize ? iBuffSize : iStrLength;
   memcpy( pPackedStrDest, my_product_name, iStrLength );
   return( iStrLength );
}
