# Define common & platform specific Source flag variables
# Authors Gautham and Yasir

# Add inputs and outputs from these tool invocations to the build variables 
COM_C_SRCS = \
./conversion.c \
./debug.c \
./memory.c \
./main.c \
./project1.c

KL25Z_C_SRCS = \
./system_MKL25Z4.c

KL25Z_S_SRCS = \
./startup_MKL25Z4.S

# Define common & platform specific include flag variables

COM_INCLUDES= \
-I ../include/common

ARM_INCLUDES= \
-I ../include/CMSIS

KL25Z_INCLUDES= \
-I ../include/kl25z
