################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Algorithm.c" \
"../Sources/AppFramework.c" \
"../Sources/AppReactionTime.c" \
"../Sources/Button.c" \
"../Sources/Buzzer.c" \
"../Sources/OLED.c" \
"../Sources/OLEDFB.c" \
"../Sources/OLEDFB3D.c" \
"../Sources/OLEDFONT.c" \
"../Sources/SnakeLogic.c" \
"../Sources/Timer.c" \
"../Sources/main.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/Algorithm.c \
../Sources/AppFramework.c \
../Sources/AppReactionTime.c \
../Sources/Button.c \
../Sources/Buzzer.c \
../Sources/OLED.c \
../Sources/OLEDFB.c \
../Sources/OLEDFB3D.c \
../Sources/OLEDFONT.c \
../Sources/SnakeLogic.c \
../Sources/Timer.c \
../Sources/main.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/Algorithm.o \
./Sources/AppFramework.o \
./Sources/AppReactionTime.o \
./Sources/Button.o \
./Sources/Buzzer.o \
./Sources/OLED.o \
./Sources/OLEDFB.o \
./Sources/OLEDFB3D.o \
./Sources/OLEDFONT.o \
./Sources/SnakeLogic.o \
./Sources/Timer.o \
./Sources/main.o \
./Sources/sa_mtb.o \

C_DEPS += \
./Sources/Algorithm.d \
./Sources/AppFramework.d \
./Sources/AppReactionTime.d \
./Sources/Button.d \
./Sources/Buzzer.d \
./Sources/OLED.d \
./Sources/OLEDFB.d \
./Sources/OLEDFB3D.d \
./Sources/OLEDFONT.d \
./Sources/SnakeLogic.d \
./Sources/Timer.d \
./Sources/main.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/Algorithm.o" \
"./Sources/AppFramework.o" \
"./Sources/AppReactionTime.o" \
"./Sources/Button.o" \
"./Sources/Buzzer.o" \
"./Sources/OLED.o" \
"./Sources/OLEDFB.o" \
"./Sources/OLEDFB3D.o" \
"./Sources/OLEDFONT.o" \
"./Sources/SnakeLogic.o" \
"./Sources/Timer.o" \
"./Sources/main.o" \
"./Sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/Algorithm.d" \
"./Sources/AppFramework.d" \
"./Sources/AppReactionTime.d" \
"./Sources/Button.d" \
"./Sources/Buzzer.d" \
"./Sources/OLED.d" \
"./Sources/OLEDFB.d" \
"./Sources/OLEDFB3D.d" \
"./Sources/OLEDFONT.d" \
"./Sources/SnakeLogic.d" \
"./Sources/Timer.d" \
"./Sources/main.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/Algorithm.o \
./Sources/AppFramework.o \
./Sources/AppReactionTime.o \
./Sources/Button.o \
./Sources/Buzzer.o \
./Sources/OLED.o \
./Sources/OLEDFB.o \
./Sources/OLEDFB3D.o \
./Sources/OLEDFONT.o \
./Sources/SnakeLogic.o \
./Sources/Timer.o \
./Sources/main.o \
./Sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/Algorithm.o: ../Sources/Algorithm.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Algorithm.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Algorithm.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/AppFramework.o: ../Sources/AppFramework.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/AppFramework.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/AppFramework.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/AppReactionTime.o: ../Sources/AppReactionTime.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/AppReactionTime.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/AppReactionTime.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Button.o: ../Sources/Button.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Button.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Button.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Buzzer.o: ../Sources/Buzzer.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Buzzer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Buzzer.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/OLED.o: ../Sources/OLED.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OLED.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OLED.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/OLEDFB.o: ../Sources/OLEDFB.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OLEDFB.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OLEDFB.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/OLEDFB3D.o: ../Sources/OLEDFB3D.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OLEDFB3D.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OLEDFB3D.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/OLEDFONT.o: ../Sources/OLEDFONT.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/OLEDFONT.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/OLEDFONT.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/SnakeLogic.o: ../Sources/SnakeLogic.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/SnakeLogic.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/SnakeLogic.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Timer.o: ../Sources/Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/Timer.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


