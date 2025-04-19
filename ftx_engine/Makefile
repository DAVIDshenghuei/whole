NAME			=	libftxengine.a

AR				=	ar rcs
CC				=	cc
RM				=	rm -rf
MAKE			=	make -C
MKDIR			=	mkdir -p
ECHO			=	/bin/echo

INC_PATH		=	includes
OBJ_PATH		=	objs
SRC_PATH		=	srcs
MINILIBX_PATH	=	minilibx-linux

MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

CFLAGS			=	-Wall -Wextra -Werror -MMD -I$(INC_PATH)
CFLAGS			+=	-I$(MINILIBX_PATH)
CFLAGS			+=	-Wno-strict-prototypes
LDFLAGS			=	-lmlx -L$(MINILIBX_PATH) -lX11 -lXext

ifneq (,$(filter debug, $(MAKECMDGOALS)))
CFLAGS			+=	-g3 -DFTX_DEBUG_ENABLED
else
CFLAGS			+=	-O2
endif

VPATH			=	$(SRC_PATH) \
					$(SRC_PATH)/internal \
					$(SRC_PATH)/core \
					$(SRC_PATH)/graphics

SRCS			=	ftx_animation1.c \
					ftx_animation2.c \
					ftx_color.c \
					ftx_core.c \
					ftx_engine.c \
					ftx_error.c \
					ftx_event.c \
					ftx_map.c \
					ftx_map_util.c \
					ftx_object.c \
					ftx_point.c \
					ftx_render.c \
					ftx_renderobject.c \
					ftx_sprite.c \
					ftx_text.c \
					ftx_texture.c \
					ftx_texture_util.c \
					ftx_window.c \
					ftx_internal_allocator.c \
					ftx_internal_deleter.c \
					ftx_internal_check.c \
					ftx_internal_engine.c \
					ftx_internal_renderer.c \
					ftx_internal_text.c \
					ftx_internal_texture.c \
					ftx_internal_window.c

OBJS			=	$(addprefix $(OBJ_PATH)/, $(notdir $(SRCS:.c=.o)))
DEPS			=	$(addprefix $(OBJ_PATH)/, $(notdir $(SRCS:.c=.d)))

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS)
	@$(ECHO) -n "Generating '$@' ... "
	@$(AR) $@ $(OBJS)
	@$(ECHO) "done"

$(MINILIBX):
	@$(MAKE) $(MINILIBX_PATH)
	@$(ECHO) "MiniLibX compilation done."

$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	@$(ECHO) -n "Compiling '$<' ... "
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(ECHO) "done"

$(OBJ_PATH):
	@$(MKDIR) $@

clean:
	@$(ECHO) -n "Cleaning ... "
	@$(RM) $(OBJS) $(DEPS)
	@$(ECHO) "done"

fclean: clean
	@$(MAKE) $(MINILIBX_PATH) clean
	@$(ECHO) "MiniLibX cleaning done."
	@$(ECHO) -n "Removing '$(NAME)' ... "
	@$(RM) $(NAME) $(OBJ_PATH)
	@$(ECHO) "done"

debug: clean all

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re debug
