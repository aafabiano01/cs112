################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application.cpp \
../PlayList.cpp \
../PlayListTester.cpp \
../Song.cpp \
../main.cpp \
../songTester.cpp 

OBJS += \
./Application.o \
./PlayList.o \
./PlayListTester.o \
./Song.o \
./main.o \
./songTester.o 

CPP_DEPS += \
./Application.d \
./PlayList.d \
./PlayListTester.d \
./Song.d \
./main.d \
./songTester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


