NAME		=		my_sokoban

MAIN		=		src/main.c

SRC			=		\

INCLUDE		=		-I include

LIB			=		-L lib/ -lmy

OBJ			=		$(SRC:%.c=%.o)
OBJMAIN		=		$(MAIN:%.c=%.o)

$(NAME):		$(OBJ) $(OBJMAIN)
				make -C lib/
				gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(INCLUDE) $(LIB)

all:			$(NAME)
clean:
				make -C lib/ clean
				$(RM) -rf $(OBJ) $(OBJMAIN)
fclean:			clean
				make -C lib/ fclean
				$(RM) -rf $(NAME)
re:				fclean all