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
** Source file containing the main loop, a basic user interface,
** as well as basic timer and serial port handling.
********************************************************************************
*/

/*
** For "timeGetTime()"
*/
#pragma comment( lib, "Winmm.lib" )

#include "windows.h"
#include "stdio.h"
#include "conio.h"

#include "abcc.h"
#include "abcc_hardware_abstraction.h"
#include "application_data_object.h"
#include "abcc_types.h"
#include "application_abcc_handler.h"

extern void TP_Shutdown( void );
extern void TP_vSetPathId( UINT32 lValue );

/*------------------------------------------------------------------------------
** RunUi()
** This function handles the user interface.
** Returns TRUE is the user have pressed the Q key.
**------------------------------------------------------------------------------
** Inputs:
**    -
**
** Outputs:
**    Returns:    - TRUE if user have pressed the "Q" key.
**
** Usage:
**    fQuit = RunUi();
**------------------------------------------------------------------------------
*/
BOOL8 RunUi( void )
{
   static char   abUserInput;
   BOOL8         fKbInput = FALSE;

   if( _kbhit() )
   {
      abUserInput = (char)_getch();
      fKbInput = TRUE;

      if( ( abUserInput == 'q' ) ||
          ( abUserInput == 'Q' ) )
      {
         /*
         ** Q is for quit.
         */
         return( TRUE );
      }
   }
   return( FALSE );
} /* End of RunUi() */

/*------------------------------------------------------------------------------
** main()
** Initializes the driver and runs the main loop.
**------------------------------------------------------------------------------
*/
int main( void )
{
   /*
   ** Make sure the ABCC reset signal is kept low by the platform specific
   ** initialization to keep the ABCC module in reset until the driver releases
   ** it.
   */
   BOOL8          fQuit = FALSE;
   APPL_AbccHandlerStatusType eAbccHandlerStatus = APPL_MODULE_NO_ERROR;
   const UINT16   iSleepTimeMS = 10;
   DWORD          lThen, lNow, lDiff;

#if( _DEBUG )
   /*
   ** Set a hard-coded Path ID if this is a debug build. In those cases we
   ** probably want to use the same, and already known, Path ID for every run.
   ** Since possible Path IDs start at '1' the value '0' means "let the user
   ** select the path".
   **
   ** For more information about Microsoft's predefined macros see
   ** https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros
   */
   TP_vSetPathId( 0 );
#endif

   if( ABCC_HwInit() != ABCC_EC_NO_ERROR )
   {
      return( 0 );
   }

   lThen = timeGetTime();

   while( !fQuit  )
   {
      eAbccHandlerStatus = APPL_HandleAbcc();
      fQuit = RunUi();
      switch( eAbccHandlerStatus )
      {
      case APPL_MODULE_NO_ERROR:
         break;
      case APPL_MODULE_RESET:
         APPL_RestartAbcc();
         break;
      case APPL_MODULE_NOT_DETECTED:
      case APPL_MODULE_NOT_SUPPORTED:
      case APPL_MODULE_NOT_ANSWERING:
      case APPL_MODULE_SHUTDOWN:
      case APPL_MODULE_UNEXPECTED_ERROR:
      default:
         printf( "\nAPPL_HandleAbcc() returned status code: %d\n", eAbccHandlerStatus );
         fQuit = TRUE;
         break;
      }

      lNow = timeGetTime();
      lDiff = lNow - lThen;
      if( lDiff > 0 )
      {
         /*
         ** Truncate intervals to 65535ms because 'ABCC_RunTimerSystem()'
         ** takes an UINT16.
         */
         if( lDiff > (UINT16)0xFFFF )
         {
            lDiff = (UINT16)0xFFFF;
         }

         ABCC_RunTimerSystem( (UINT16)lDiff );
         lThen = lNow;
      }

      /*
      ** 'Sleep(0)' gives up the remaining time slice, so only
      ** sleep if X > 0.
      */
      if( iSleepTimeMS > 0 )
      {
         Sleep( iSleepTimeMS );
      }
   }

   TP_Shutdown();

   if( eAbccHandlerStatus != APPL_MODULE_NO_ERROR )
   {
      printf( "Press any key to quit.\n" );
      while( !_kbhit() )
      {
         Sleep( 100 );
      }
   }

   return ( 0 );

} /* End of main() */
