/******************************************************************************
* 
* File Name: oledTask.c
*
*******************************************************************************
* Copyright 2021-2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/
/******************************************************************************
* This file contains the task that demonstrates
* controlling an OLED display using the emWin Graphics Library.
* The project displays a start up screen with Cypress logo and text "EMWIN
* DEMO" followed by an instructions screen.  Pressing SW2 on the Pioneer kit
* scrolls through the following display pages that demonstrate various features
* of emWin library.
*
*   1. A screen showing a text box with wrapped text
*   2. A screen showing normal fonts
*   3. A screen showing bold fonts
*   4. A screen showing various text alignments, styles and modes
*   5. A screen showing 2D graphics with vertical lines of various thickness
*       rounded rectangles and circles
*
 *******************************************************************************/
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "GUI.h"
#include "mtb_ssd1306.h"
#include "mtb_ssd1306_i2c.h"
#include "FreeRTOS.h"
#include "task.h"
#include "images.h"

/*******************************************************************************
* Macros
*******************************************************************************/
/* I2C bus speed */
#define I2C_SPEED                           (400000)

/* Number of demo pages */
#define NUMBER_OF_DEMO_PAGES    (sizeof(demoPageArray)/sizeof(demoPageArray[0]))

/* Delay after startup screen in milliseconds */
#define DELAY_AFTER_STARTUP_SCREEN_MS       (2000)

/*******************************************************************************
* Forward declaration
*******************************************************************************/
/* Function prototypes */
void ShowFontSizesNormal(void);
void ShowFontSizesBold(void);
void ShowTextAlignments(void);
void ShowTextStyles(void);
void ShowTextWrapAndOrientation(void);
void Show2DGraphics(void);

/* Array of demo pages functions */
void (*demoPageArray[])(void) = {
    ShowTextWrapAndOrientation,
    ShowFontSizesNormal,
    ShowFontSizesBold,
    ShowTextAlignments,
    ShowTextStyles,
    Show2DGraphics
};

/*******************************************************************************
* Function Name: void ShowStartupScreen(void)
********************************************************************************
*
* Summary: This function displays the startup screen with Cypress Logo and
*            the demo description text
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowStartupScreen(void)
{
    /* Set foreground and background color and font size */
    GUI_SetFont(GUI_FONT_13B_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();

    GUI_DrawBitmap(&bmCypress_Logo_1_BPP_Inv, 0, 0);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("EMWIN DEMO", 64, 42);
}

/*******************************************************************************
* Function Name: void ShowInstructionsScreen(void)
********************************************************************************
*
* Summary: This function shows screen with instructions to press SW2 to
*            scroll through various display pages
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowInstructionsScreen(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_8_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display instructions text */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("PRESS SW2 ON THE KIT", 64, 2);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("TO SCROLL THROUGH ", 64, 14);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("DEMO PAGES!", 64, 26);
}


/*******************************************************************************
* Function Name: void ShowFontSizesNormal(void)
********************************************************************************
*
* Summary: This function shows various font sizes
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowFontSizesNormal(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_10_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("NORMAL FONTS", 64, 1);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Font8_1*/
    GUI_SetFont(GUI_FONT_8_1);
    GUI_DispStringAt("GUI_Font8_1", 2, 20);

    /* Font10_1*/
    GUI_SetFont(GUI_FONT_10_1);
    GUI_DispStringAt("GUI_Font10_1", 2, 30);

    /* Font13_1*/
    GUI_SetFont(GUI_FONT_13_1);
    GUI_DispStringAt("GUI_Font13_1", 2, 40);
}


/*******************************************************************************
* Function Name: void ShowFontSizesBold(void)
********************************************************************************
*
* Summary: This function shows various font sizes
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowFontSizesBold(void)
{
    /* Set font size, background color and text mode */
    GUI_SetFont(GUI_FONT_10_1);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_NORMAL);

    /* Clear the display */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("BOLD FONTS", 64, 1);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Font13B_1*/
    GUI_SetFont(GUI_FONT_13B_1);
    GUI_DispStringAt("GUI_Font13B_1", 2, 18);

    /* Font13HB_1*/
    GUI_SetFont(GUI_FONT_13HB_1);
    GUI_DispStringAt("GUI_Font13HB_1", 2, 33);

    /* Font16B_1*/
    GUI_SetFont(GUI_FONT_16B_1);
    GUI_DispStringAt("GUI_Font16B_1", 2, 48);
}


/*******************************************************************************
* Function Name: void ShowTextAlignments(void)
********************************************************************************
*
* Summary: This function displays the following text alignments
*            1. Left, Center and Right aligned text
*            2. Underline, overline and strikethrough style text
*            3. Normal, reverse, transparent and XOR text modes
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowTextAlignments(void)
{
    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_10_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);
    
    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("TEXT ALIGNMENT", 64, 1);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    GUI_SetFont(GUI_FONT_8_1);

    /* Display left aligned text */
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("ALIGNMENT LEFT", 0, 20);

    /* Display center aligned text */
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("ALIGNMENT CENTER", 64, 30);

    /* Display right aligned text */
    GUI_SetTextAlign(GUI_TA_RIGHT);
    GUI_DispStringAt("ALIGNMENT RIGHT", 127, 40);
}

/*******************************************************************************
* Function Name: void ShowTextStyles(void)
********************************************************************************
*
* Summary: This function displays the following text styles
*            Underline, overline and strikethrough style text
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowTextStyles(void)
{
    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_10_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);
    
    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("TEXT STYLES", 64, 1);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    GUI_SetFont(GUI_FONT_8_1);

    /* Display underlined text */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("UNDERLINED TEXT", 1, 16);

    /* Display overlined text */
    GUI_SetTextStyle(GUI_TS_OVERLINE);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("OVERLINED TEXT", 1, 28);

    /* Display strikethrough text */
    GUI_SetTextStyle(GUI_TS_STRIKETHRU);
    GUI_SetTextAlign(GUI_TA_LEFT);
    GUI_DispStringAt("STRIKETHROUGH TEXT", 1, 40);

    /* Display text in reverse mode. This will print black text n
        a white box */
    GUI_SetTextStyle(GUI_TS_NORMAL);
    GUI_SetTextMode(GUI_TM_REV);
    GUI_DispStringAt("INVERSE TEXT", 1, 52);

}

/*******************************************************************************
* Function Name: void ShowTextWrapAndOrientation(void)
********************************************************************************
*
* Summary: This function shows the text orientation and text wrap functions
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ShowTextWrapAndOrientation(void)
{
    GUI_RECT leftRect = {0, 0, 11, 63};
    GUI_RECT rightRect = {116, 0, 127, 63};
    GUI_RECT middleRect = {12, 0, 126, 63};
    GUI_RECT middleRectMargins = {14, 2, 124, 61};

    const char leftText[] = "TEXT CCW";
    const char rightText[] = "TEXT CW";

    const char middleText[] = "This project demonstrates emWin Graphics Library. \n\nThis page shows the text wrap and text rotation features.";

    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_8_1);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);

    /* Clear the screen */
    GUI_Clear();

    /* Draw rectangles to hold text */
    GUI_DrawRectEx(&leftRect);
    GUI_DrawRectEx(&rightRect);
    GUI_DrawRectEx(&middleRect);

    /* Display string in left rectangle rotated counter clockwise */
    GUI_DispStringInRectEx(leftText, &leftRect, GUI_TA_HCENTER | GUI_TA_VCENTER, strlen(leftText), GUI_ROTATE_CCW);

    /* Display string in right rectangle rotated clockwise */
    GUI_DispStringInRectEx(rightText, &rightRect, GUI_TA_HCENTER | GUI_TA_VCENTER, strlen(rightText), GUI_ROTATE_CW);

    /* Display string in middle rectangle with word wrap */
    GUI_DispStringInRectWrap(middleText, &middleRectMargins, GUI_TA_LEFT, GUI_WRAPMODE_WORD);
}


/*******************************************************************************
* Function Name: void Show2DGraphics(void)
********************************************************************************
*
* Summary: This function displays the following 2D graphics
*            1. Horizontal lines with various pen widths
*            2. Vertical lines with various pen widths
*            3. Arcs
*            4. Filled rounded rectangle
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Show2DGraphics(void)
{
    /* Set font size, foreground and background colors */
    GUI_SetFont(GUI_FONT_10_1);
    GUI_SetColor(GUI_WHITE);
    GUI_SetBkColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_NORMAL);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Clear the screen */
    GUI_Clear();

    /* Display page title */
    GUI_SetTextStyle(GUI_TS_UNDERLINE);
    GUI_SetTextAlign(GUI_TA_HCENTER);
    GUI_DispStringAt("2D SHAPES", 64, 1);
    GUI_SetTextStyle(GUI_TS_NORMAL);

    /* Vertical lines */
    GUI_SetPenSize(1);
    GUI_DrawLine(1, 15, 1, 61);
    GUI_SetPenSize(2);
    GUI_DrawLine(5, 15, 5, 61);
    GUI_SetPenSize(3);
    GUI_DrawLine(10, 15, 10, 61);
    GUI_SetPenSize(4);
    GUI_DrawLine(108, 15, 108, 61);
    GUI_SetPenSize(5);
    GUI_DrawLine(115, 15, 115, 61);
    GUI_SetPenSize(6);
    GUI_DrawLine(122, 15, 122, 61);

    /* Rounded rectangles and circle */
    GUI_DrawRoundedRect(15, 15, 102, 62, 2);
    GUI_DrawRoundedRect(18, 18, 99, 59, 2);
    GUI_DrawRoundedRect(21, 21, 96, 56, 2);
    GUI_DrawCircle(59, 39, 15);
    GUI_DrawCircle(59, 39, 12);
    GUI_DrawCircle(59, 39, 9);
}


/*******************************************************************************
* Function Name: void WaitforSwitchPressAndRelease(void)
********************************************************************************
*
* Summary: This implements a simple "Wait for button press and release"
*           function.  It first waits for the button to be pressed and then
*           waits for the button to be released.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This is a blocking function and exits only on a button press and release
*
*******************************************************************************/
void WaitforSwitchPressAndRelease(void)
{
    /* Wait for SW2 to be pressed */
    while( CYBSP_BTN_PRESSED != cyhal_gpio_read(CYBSP_USER_BTN));

    /* Wait for SW2 to be released */
    while( CYBSP_BTN_PRESSED == cyhal_gpio_read(CYBSP_USER_BTN));
}

/*******************************************************************************
* Function Name: int oledTask(void *arg)
********************************************************************************
*
* Summary: This is the entry function of the task.  Following operations are
*           performed in this function
*           1. emWin GUI is initialized
*           2. Startup screen with CY logo is displayed for 2 seconds
*           3. Instructions screen is displayed
*           4. On every key press of SW2 on the kit, the program scrolls through
*               following demo pages
*                   a. Text orientation and text wrap
*                   b. Normal fonts
*                   c. Bold fonts
*                   e. Text alignments
*                   f. Text styles
*                   g. 2D graphics with lines of various thickness, rectangles
*                       and circles.
*
* Parameters:
*  void* arg : argument to task if any
*
* Return:
*  None
*
*******************************************************************************/
void oledTask(void *arg)
{
    uint8_t pageNumber = 0;
    cy_rslt_t result;
    cyhal_i2c_t i2c_obj;

    /* Configuration to initialize the I2C block */
    cyhal_i2c_cfg_t i2c_config = {
        .is_slave = false,
        .address = OLED_I2C_ADDRESS,
        .frequencyhal_hz = I2C_SPEED
    };

    /* Initialize and configure the I2C to use with the OLED display */
    result = cyhal_i2c_init( &i2c_obj, CYBSP_I2C_SDA,
            CYBSP_I2C_SCL, NULL);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    result = cyhal_i2c_configure(&i2c_obj, &i2c_config);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* Initialize the OLED display */
    result = mtb_ssd1306_init_i2c(&i2c_obj);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* To avoid compiler warning */
    (void)result;

    /* Initialize emWin GUI */
    GUI_Init();

    /* Configure Switch and LEDs*/
    cyhal_gpio_init( CYBSP_USER_BTN, CYHAL_GPIO_DIR_INPUT,
                     CYHAL_GPIO_DRIVE_PULLUP, CYBSP_BTN_OFF);

    /* Display startup screen for 2 seconds */
    ShowStartupScreen();

    vTaskDelay(DELAY_AFTER_STARTUP_SCREEN_MS);

    /* Show the instructions screen */
    ShowInstructionsScreen();

    for (;;)
    {
        /* Wait for a switch press event */
        WaitforSwitchPressAndRelease();

        /* Using pageNumber as index, update the display with a demo screen */
        (*demoPageArray[pageNumber])();

        /* Cycle through page numbers */
        pageNumber = (pageNumber + 1) % NUMBER_OF_DEMO_PAGES;
    }
}
/* END OF FILE */
