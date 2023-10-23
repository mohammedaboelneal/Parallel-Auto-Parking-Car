################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./APP/DCM_App/NTI_DC_MOTOR_APP.obj" \
"./APP/US_App/US_App.obj" \
"./HAL/DC_Motors/DC_MOTOR_L298.obj" \
"./HAL/Leds/Led.obj" \
"./HAL/Leds/RGB_Leds.obj" \
"./HAL/UltraSonic_HCSR04/ultrasonic.obj" \
"./MCAL/GPIO/Gpio.obj" \
"./MCAL/GP_TIMERS/GP_Timers.obj" \
"./MCAL/PWM/PWM.obj" \
"./MCAL/RCC/RCC.obj" \
"./MCAL/SysTick/Delay/delay.obj" \
"./MCAL/SysTick/SysTick.obj" \
"./SYS_CTRL/Sys_Ctrl.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include APP/DCM_App/subdir_vars.mk
-include APP/US_App/subdir_vars.mk
-include HAL/DC_Motors/subdir_vars.mk
-include HAL/Leds/subdir_vars.mk
-include HAL/UltraSonic_HCSR04/subdir_vars.mk
-include MCAL/GPIO/subdir_vars.mk
-include MCAL/GP_TIMERS/subdir_vars.mk
-include MCAL/PWM/subdir_vars.mk
-include MCAL/RCC/subdir_vars.mk
-include MCAL/SysTick/Delay/subdir_vars.mk
-include MCAL/SysTick/subdir_vars.mk
-include SYS_CTRL/subdir_vars.mk
-include subdir_rules.mk
-include APP/DCM_App/subdir_rules.mk
-include APP/US_App/subdir_rules.mk
-include HAL/DC_Motors/subdir_rules.mk
-include HAL/Leds/subdir_rules.mk
-include HAL/UltraSonic_HCSR04/subdir_rules.mk
-include MCAL/GPIO/subdir_rules.mk
-include MCAL/GP_TIMERS/subdir_rules.mk
-include MCAL/PWM/subdir_rules.mk
-include MCAL/RCC/subdir_rules.mk
-include MCAL/SysTick/Delay/subdir_rules.mk
-include MCAL/SysTick/subdir_rules.mk
-include SYS_CTRL/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
NTI_Parallel_AutoParking.out \

EXE_OUTPUTS__QUOTED += \
"NTI_Parallel_AutoParking.out" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "NTI_Parallel_AutoParking.out"

# Tool invocations
NTI_Parallel_AutoParking.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"NTI_Parallel_AutoParking.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="NTI_Parallel_AutoParking_linkInfo.xml" --rom_model -o "NTI_Parallel_AutoParking.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "APP\DCM_App\NTI_DC_MOTOR_APP.obj" "APP\US_App\US_App.obj" "HAL\DC_Motors\DC_MOTOR_L298.obj" "HAL\Leds\Led.obj" "HAL\Leds\RGB_Leds.obj" "HAL\UltraSonic_HCSR04\ultrasonic.obj" "MCAL\GPIO\Gpio.obj" "MCAL\GP_TIMERS\GP_Timers.obj" "MCAL\PWM\PWM.obj" "MCAL\RCC\RCC.obj" "MCAL\SysTick\Delay\delay.obj" "MCAL\SysTick\SysTick.obj" "SYS_CTRL\Sys_Ctrl.obj" 
	-$(RM) "main.d" "tm4c123gh6pm_startup_ccs.d" "APP\DCM_App\NTI_DC_MOTOR_APP.d" "APP\US_App\US_App.d" "HAL\DC_Motors\DC_MOTOR_L298.d" "HAL\Leds\Led.d" "HAL\Leds\RGB_Leds.d" "HAL\UltraSonic_HCSR04\ultrasonic.d" "MCAL\GPIO\Gpio.d" "MCAL\GP_TIMERS\GP_Timers.d" "MCAL\PWM\PWM.d" "MCAL\RCC\RCC.d" "MCAL\SysTick\Delay\delay.d" "MCAL\SysTick\SysTick.d" "SYS_CTRL\Sys_Ctrl.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

