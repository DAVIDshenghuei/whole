################################################################################
###
### Default Makefile
###
################################################################################

CC			=	cc
CP			=	cp
RM			=	rm -rf
ECHO		=	echo
MAKE		=	make -C
MKDIR		=	mkdir -p

FTX			=	libftxengine.a

CFLAGS		=	-Wall -Wextra -Werror -MMD -I$(FTX_PATH)
CFLAGS		+=	$(CFLAGS_EXTRA)
ifneq (, $(INCS_PATH))
CFLAGS		+=	-I$(INCS_PATH)
endif

LDFLAGS		=	-L$(FTX_PATH) -lftxengine
LDFLAGS		+=	-L$(FTX_PATH)/minilibx-linux/ -lmlx -lX11 -lXext
LDFLAGS		+=	$(LDFLAGS_EXTRA)

ifneq (, $(OBJS_PATH))
OBJS		=	$(addprefix $(OBJS_PATH)/, $(notdir $(SRCS:.c=.o)))
DEPS		=	$(addprefix $(OBJS_PATH)/, $(notdir $(SRCS:.c=.d)))
else
OBJS		=	$(notdir $(SRCS:.c=.o))
DEPS		=	$(notdir $(SRCS:.c=.o))
endif

all: $(NAME)
	@$(ECHO) "\033[92mCompilation finished.\033[0m"

$(FTX):
	$(MAKE) $(FTX_PATH)
	$(CP) $(FTX_PATH)/$(FTX) $@

$(NAME): $(FTX) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJS_PATH)/%.o: %.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(DEPS)
	$(MAKE) $(FTX_PATH) clean

fclean: clean
	$(RM) $(OBJS_PATH) $(NAME) $(FTX)
	$(MAKE) $(FTX_PATH) fclean

re: fclean all

engine:
	$(MAKE) $(FTX_PATH)
	$(CP) $(FTX_PATH)/$(FTX) $(FTX)

$(OBJS_PATH):
	$(MKDIR) $@

-include $(DEPS)

.PHONY: all clean fclean re
