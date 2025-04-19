################################################################################
###
### 42X Engine
###
################################################################################

### [REQUIRED] Name of the executable
NAME			=	cub3d

### [REQUIRED] 42X Engine header path
FTX_PATH		=	ftx_engine

### Header files directory
INCS_PATH		=	

### Source files directory
SRCS_PATH		=	

### Object files directory
OBJS_PATH		=	objs

### Add extra flags to the compiler, default flags are `-Wall -Wextra -Werror`
CFLAGS_EXTRA	=	

### Add extra linker flags
LDFLAGS_EXTRA	=	

### List of all source files
SRCS			=	main.c

include default.mk
