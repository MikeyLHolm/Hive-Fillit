COMPILER = GCC

NAME = fillit

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

SRC = ./helpers.c ./list.c ./listloader.c ./fillit.c ./stage.c ./readmain.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(COMPILER) $(OBJ) libft.a -o $(NAME)

$(OBJ):
	@$(COMPILER) -c $(FLAGS) $(SRC) 

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

norme:
	@norminette ./libft
	@norminette $(SRC)
	@norminette ./fillit.h

re: fclean all

.PHONY: clean fclean all re
