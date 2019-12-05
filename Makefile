NAME		=		my_sokoban

MAIN		=		src/main.c

SRC			=		src/map/map.c 	\
					src/map/map_player.c		\
					src/objects/map_o.c			\
					src/objects/map_info_o.c	\
					src/objects/types_o.c		\
					src/map/map_display.c

INCLUDE		=		-I include

LIB			=		-L lib/ -lmy

OBJ			=		$(SRC:%.c=%.o)
OBJMAIN		=		$(MAIN:%.c=%.o)

CFLAGS		=		-lncurses $(INCLUDE)

$(NAME):		$(OBJ) $(OBJMAIN)
				make -C lib/
				gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(INCLUDE) $(LIB) $(CFLAGS)

all:			$(NAME)
clean:
				make -C lib/ clean
				$(RM) -rf $(OBJ) $(OBJMAIN)
fclean:			clean
				make -C lib/ fclean
				$(RM) -rf $(NAME)
re:				fclean all