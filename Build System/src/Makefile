-include sources.mk
HOST=0
KL25Z=1
BBB=2
PLATFORM=KL25Z
#Define common compiler flags
COM_CFLG=  \
-Wall \
-Werror \
-g \
-O0 \
-std=c99 \
-DPROJECT1

#Define KL25z flags
KL25Z_ARCH=thumb
KL25Z_CPU=cortex-m0plus

KL25Z_CFLG= \
-mcpu=$(KL25Z_CPU) \
-mthumb \
-mfloat-abi=soft\
-mfpu=fpv4-sp-d16
-specs=nosys.specs

KL25Z_LDFLAGS=-T ../platform/MKL25Z128xxx4_flash.ld
# Define BBB specific compiler flags
BBB_CPU=cortex-a8

BBB_CFLAGS= \
-mcpu=$(BBB_CPU) \
-mthumb
-mfloat-abi=hard

ifeq ($(PLATFORM),HOST)
CC=gcc
CFLAGS=$(COM_CFLG)
SOURCES=$(COM_C_SRCS)
INCLUDES=$(COM_INCLUDES) $(ARM_INCLUDES)
LDFLAGS=
else ifeq ($(PLATFORM),KL25Z) 
CC=arm-none-eabi-gcc 
CFLAGS=$(COM_CFLG) $(KL25Z_CFLG)
SOURCES=$(COM_C_SRCS) $(KL25Z_C_SRCS) $(KL25Z_S_SRCS)
INCLUDES=$(COM_INCLUDES) $(ARM_INCLUDES) $(KL25Z_INCLUDES)
LDFLAGS=$(KL25Z_LDFLAGS)
else  #BBB
CC=arm-linux-gnueabihf-gcc 
CFLAGS=$(COM_CFLG) $(BBB_CFLAGS)
SOURCES=$(COM_C_SRCS)
INCLUDES=$(COM_INCLUDES) $(ARM_INCLUDES) 
LDFLAGS=  
endif

ifeq ($(PLATFORM),KL25Z)
OBJS:= $(COM_C_SRCS:.c=.o) $(KL25Z_C_SRCS:.c=.o) $(KL25Z_S_SRCS:.S=.o)
C_DEPS:= $(COM_C_SRCS:.c=.d) $(KL25Z_C_SRCS:.c=.d) $(KL25Z_S_SRCS:.S=.d)
else
OBJS:= $(SOURCES:.c=.o)
C_DEPS:= $(SOURCES:.c=.d)
endif

.PHONY: compile-all build clean

#Targets
%.i: %.c
	-@echo 'Creating preprocessor file .i '
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@
	-@echo ' '
	
%.asm: %.c
	-@echo 'Creating assembly file..'
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@
	-@echo ' '
	
%.o: %.c
	-@echo 'Creating object file from .c file..'
	-$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	-@echo ' '

%.o: %.S
	-@echo 'Creating object file from .S file..'
	-$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	-@echo ' '
	
%.d: %.c
	-@echo 'Creating dependency file for .c file..'
	-$(CC) $(CPPFLAG) $(CFLAGS) $(INCLUDES) -M $< -o $@
	-@echo ' '

%.d: %.S
	-@echo 'Creating dependency file for .S file..'
	-$(CC) $(CPPFLAG) $(CFLAGS) $(INCLUDES) -M $< -o $@
	-@echo ' '
	
compile-all:$(OBJS)

build:$(OBJS) $(C_DEPS)
	-@echo 'building..'
	-$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -Xlinker -Map=project1.map -o project1.elf $(OBJS)
	-$ size --format=SysV project1.elf
	-ls -sh project1.elf
	-@echo ' '

clean:
	-@echo 'Cleaning the already  generated files'
	-$(RM) *.o *.d *.i *.asm *.out project1.elf project1.map
	-@echo ' '
