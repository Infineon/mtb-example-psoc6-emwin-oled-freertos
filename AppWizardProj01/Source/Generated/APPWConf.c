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
File        : APPWConf.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "AppWizard.h"
#include "Resource.h"

#ifdef WIN32
  #include "GUIDRV_Win32R.h"
#endif

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define XSIZE_PHYS       128
#define YSIZE_PHYS       64
#define COLOR_CONVERSION GUICC_1
#define DISPLAY_DRIVER   GUIDRV_WIN32R
#define NUM_BUFFERS      2
#define _aVarList        NULL
#define _aScrollerList   NULL
#define _NumScrollers    0

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _apRootList
*/
static APPW_ROOT_INFO * _apRootList[] = {
  &ID_SCREEN_00_RootInfo,
  &ID_SCREEN_01_RootInfo,
  &ID_SCREEN_02_RootInfo,
  &ID_SCREEN_03_RootInfo,
  &ID_SCREEN_04_RootInfo,
  &ID_SCREEN_05_RootInfo,
  &ID_SCREEN_06_RootInfo,
  &ID_SCREEN_07_RootInfo,
  &ID_SCREEN_08_RootInfo,
};

/*********************************************************************
*
*       _NumScreens
*/
static unsigned _NumScreens = GUI_COUNTOF(_apRootList);

/*********************************************************************
*
*       _NumVars
*/
static unsigned _NumVars = 0;

/*********************************************************************
*
*       ID_DRAW_000
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_8, 3) {
  APPW_ID_DRAW_HLINE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)NULL,
  { { 0x0000000e, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000080, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_7, 3) {
  APPW_ID_DRAW_CIRCLE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_8,
  { { 0x00000040, 0, ATOM_CONSTANT, 0 },
    { 0x00000027, 0, ATOM_CONSTANT, 0 },
    { 0x00000013, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_6, 5) {
  APPW_ID_AA_FILL_ROUNDED_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_7,
  { { 0x0000006c, 0, ATOM_CONSTANT, 0 },
    { 0x00000010, 0, ATOM_CONSTANT, 0 },
    { 0x0000007f, 0, ATOM_CONSTANT, 0 },
    { 0x0000003e, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_5, 5) {
  APPW_ID_AA_FILL_ROUNDED_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_6,
  { { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000010, 0, ATOM_CONSTANT, 0 },
    { 0x00000012, 0, ATOM_CONSTANT, 0 },
    { 0x0000003e, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_4, 3) {
  APPW_ID_DRAW_CIRCLE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_5,
  { { 0x00000040, 0, ATOM_CONSTANT, 0 },
    { 0x00000027, 0, ATOM_CONSTANT, 0 },
    { 0x0000000d, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_3, 5) {
  APPW_ID_DRAW_ROUNDED_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_4,
  { { 0x00000016, 0, ATOM_CONSTANT, 0 },
    { 0x00000012, 0, ATOM_CONSTANT, 0 },
    { 0x00000068, 0, ATOM_CONSTANT, 0 },
    { 0x0000003c, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_2, 5) {
  APPW_ID_DRAW_ROUNDED_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_3,
  { { 0x00000014, 0, ATOM_CONSTANT, 0 },
    { 0x00000010, 0, ATOM_CONSTANT, 0 },
    { 0x0000006a, 0, ATOM_CONSTANT, 0 },
    { 0x0000003e, 0, ATOM_CONSTANT, 0 },
    { 0x00000005, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_1, 3) {
  APPW_ID_DRAW_CIRCLE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_2,
  { { 0x00000040, 0, ATOM_CONSTANT, 0 },
    { 0x00000027, 0, ATOM_CONSTANT, 0 },
    { 0x00000011, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_000_Item_0, 3) {
  APPW_ID_DRAW_CIRCLE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_1,
  { { 0x00000040, 0, ATOM_CONSTANT, 0 },
    { 0x00000027, 0, ATOM_CONSTANT, 0 },
    { 0x0000000f, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_001
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_3, 3) {
  APPW_ID_DRAW_HLINE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)NULL,
  { { 0x0000000e, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000080, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_2, 3) {
  APPW_ID_DRAW_HLINE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_3,
  { { 0x0000001e, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000050, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_1, 3) {
  APPW_ID_DRAW_HLINE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_2,
  { { 0x0000001b, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000054, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_001_Item_0, 3) {
  APPW_ID_DRAW_HLINE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_1,
  { { 0x0000002e, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000073, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_002
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_002_Item_0, 3) {
  APPW_ID_DRAW_HLINE,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)NULL,
  { { 0x0000000e, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000080, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       ID_DRAW_003
*/
APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_2, 4) {
  APPW_ID_DRAW_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)NULL,
  { { 0x0000000e, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000071, 0, ATOM_CONSTANT, 0 },
    { 0x0000003f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_1, 4) {
  APPW_ID_DRAW_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_2,
  { { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x0000000e, 0, ATOM_CONSTANT, 0 },
    { 0x0000003f, 0, ATOM_CONSTANT, 0 }
  }
};

APPW_DRAWING_ITEM_DEF_X(_aID_DRAW_003_Item_0, 4) {
  APPW_ID_DRAW_RECT,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_1,
  { { 0x00000072, 0, ATOM_CONSTANT, 0 },
    { 0x00000000, 0, ATOM_CONSTANT, 0 },
    { 0x0000007f, 0, ATOM_CONSTANT, 0 },
    { 0x0000003f, 0, ATOM_CONSTANT, 0 }
  }
};

/*********************************************************************
*
*       _appDrawing
*/
static GUI_CONST_STORAGE APPW_DRAWING_ITEM * _appDrawing[] = {
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_000_Item_0,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_001_Item_0,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_002_Item_0,
  (GUI_CONST_STORAGE APPW_DRAWING_ITEM *)&_aID_DRAW_003_Item_0
};

/*********************************************************************
*
*       _NumDrawings
*/
static unsigned _NumDrawings = GUI_COUNTOF(_appDrawing);

/*********************************************************************
*
*       Multibuffering
*/
static U8 _MultibufEnable = 0;

/*********************************************************************
*
*       _ShowMissingCharacters
*/
static U8 _ShowMissingCharacters = 0;

/*********************************************************************
*
*       _apLang
*/
static GUI_CONST_STORAGE char * _apLang[] = {
  (GUI_CONST_STORAGE char *)acAPPW_Language_0,
};

/*********************************************************************
*
*       _TextInit
*/
static GUI_CONST_STORAGE APPW_TEXT_INIT _TextInit = {
  _apLang,
  GUI_COUNTOF(_apLang),
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _InitText
*/
static void _InitText(void) {
  APPW_TextInitMem(&_TextInit);
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       APPW_X_Setup
*/
void APPW_X_Setup(void) {
  APPW_SetpfInitText(_InitText);
  APPW_X_FS_Init();
  APPW_MULTIBUF_Enable(_MultibufEnable);
  APPW_SetData(_apRootList, _NumScreens, _aVarList, _NumVars, _aScrollerList, _NumScrollers, (APPW_DRAWING_ITEM **)_appDrawing, _NumDrawings);
  APPW_SetSupportScroller(0);
  GUI_ShowMissingCharacters(_ShowMissingCharacters);
}

/*********************************************************************
*
*       APPW_X_Config
*/
#ifdef WIN32
void APPW_X_Config(void) {
  GUI_MULTIBUF_Config(NUM_BUFFERS);
  GUI_DEVICE_CreateAndLink(DISPLAY_DRIVER, COLOR_CONVERSION, 0, 0);
  if (LCD_GetSwapXY()) {
    LCD_SetSizeEx (0, YSIZE_PHYS, XSIZE_PHYS);
    LCD_SetVSizeEx(0, YSIZE_PHYS, XSIZE_PHYS);
  } else {
    LCD_SetSizeEx (0, XSIZE_PHYS, YSIZE_PHYS);
    LCD_SetVSizeEx(0, XSIZE_PHYS, YSIZE_PHYS);
  }
}
#endif

/*************************** End of file ****************************/
