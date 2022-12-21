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
* controlling an OLED display using the emWin Graphics Library and
* AppWizard GUI design tool.
* The project displays a start up screen with Infineon logo and text "EMWIN
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

/*******************************************************************************
* Macros
*******************************************************************************/
/* I2C bus speed */
#define I2C_SPEED                           (400000)

/*******************************************************************************
* Forward declaration
*******************************************************************************/

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

    /* Configure Switch and LEDs*/
    cyhal_gpio_init( CYBSP_USER_BTN, CYHAL_GPIO_DIR_INPUT,
                     CYHAL_GPIO_DRIVE_PULLUP, CYBSP_BTN_OFF);
    CY_ASSERT(result == CY_RSLT_SUCCESS);
    /* Initialize the User LED */
    result = cyhal_gpio_init( CYBSP_USER_LED, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG,
                     CYBSP_LED_STATE_OFF);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* Display startup screen for 2 seconds */

    /* Calling the Appwizard application entry point*/
    MainTask();

}

/* END OF FILE */
