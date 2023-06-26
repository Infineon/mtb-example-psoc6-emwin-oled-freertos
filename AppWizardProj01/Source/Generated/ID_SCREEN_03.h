/*********************************************************************
*                     SEGGER Microcontroller GmbH                    *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2023  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File        : ID_SCREEN_03.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef ID_SCREEN_03_H
#define ID_SCREEN_03_H

#include "AppWizard.h"

/*********************************************************************
*
*       Objects
*/
#define ID_BOX_00   (GUI_ID_USER + 1)
#define ID_TEXT_04  (GUI_ID_USER + 9)
#define ID_TEXT_05  (GUI_ID_USER + 10)
#define ID_TIMER_00 (GUI_ID_USER + 11)
#define ID_TEXT_06  (GUI_ID_USER + 12)

/*********************************************************************
*
*       Slots
*/
void ID_SCREEN_03__APPW_NOTIFICATION_INITDIALOG        (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_03__ID_TIMER_00__APPW_NOTIFICATION_TIMER(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);

/*********************************************************************
*
*       Callback
*/
void cbID_SCREEN_03(WM_MESSAGE * pMsg);

#endif  // ID_SCREEN_03_H

/*************************** End of file ****************************/
