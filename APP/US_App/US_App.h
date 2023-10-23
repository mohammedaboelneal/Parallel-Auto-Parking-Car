/*
 *      @file       :   US_App.h
 *
 *      @Created on :   Sep 19, 2023
 *      @Author     :   AVELABS Group 1
 *      @Brief      :   This file contains all prototypes for the interfaces can be used In The Main Application to use the ultra-sonic module
 *
 *      @about      :   In This Project 4 Ultra-Sonic Modules used to get distances for parking
 *
 *
 *        =========================================================================================
 *      ||    ------------                                                       ------------      ||
 *      ||   |     U.S    |                                                     |    U.S     |     ||
 *      ||   |      1     |                                                     |     2      |     ||
 *      ||    ------------                                                       ------------      ||
 *      ||                                                                                         ||
 *      ||    --------                                                                --------     ||
 *      ||   |        |                                                              |        |    ||
 *      ||   |   U.S  |                                                              |  U.S   |    ||
 *      ||   |    3   |                                                              |   4    |    ||
 *      ||   |        |                                                               --------     ||
 *      ||    --------                                                                             ||
 *      ||                                                                                         ||
 *      ||                                   This The Car Kit                                      ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *      ||                                                                                         ||
 *        =========================================================================================
 *
 */

#ifndef APP_US_APP_US_APP_H_
#define APP_US_APP_US_APP_H_

/*****************************  Includes Sections ***************************/
#include "NTI_ULTRASONIC_Cfg.h"
#include "../../HAL/UltraSonic_HCSR04/ultrasonic.h"

/*********************** Services Prototype ******************************/
/*  @Service name           : US_InitAllModules
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Initialize all Ultra-sonic modules in the Project
 *  @Expected Output        : All Modules are ready to be used
 * */
void US_InitAllModules(void);

/*  @Service name           : US1_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 1
 *  @Expected Output        : distance of module 1
 * */
u32 US1_GetDistance(void);

/*  @Service name           : US2_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 2
 *  @Expected Output        : distance of module 2
 * */
u32 US2_GetDistance(void);

/*  @Service name           : US3_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 3
 *  @Expected Output        : distance of module 3
 * */
u32 US3_GetDistance(void);

/*  @Service name           : US4_GetDistance
 *  @Parameters (in)        : None
 *  @Parameters (out)       : None
 *  @Return value           : None
 *  @Operation Constrains   : None
 *  @Brief                  : Function used to Get The Distance from module 4
 *  @Expected Output        : distance of module 4
 * */
u32 US4_GetDistance(void);

#endif /* APP_US_APP_US_APP_H_ */
