GB = base_game/libbasegame.a
NAME = game_cube

FIL = plateforme_manager

S = $(foreach f, $(FIL), srcs/$(f).c)
OBJ = $(S:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I headers/ -I base_game/minilibx/include/MLX42/ -I base_game/headers/ -I base_game/libft/headers/
G_FLAGS = -fsanitize=address -g3 base_game/minilibx/libmlx42.a -lglfw -L "/Users/$(shell echo $(USER))/.brew/opt/glfw/lib/"

C1			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/200")
C2			= $(shell bc <<< "((($(CMP_COUNT)*100)/($(CMP_TOTAL) / 2))*255)/100")
C4			= $(shell bc <<< "255 - (((($(CMP_COUNT) - ($(CMP_TOTAL) / 2))*100)/($(CMP_TOTAL) / 2))*255)/100")
C5			= $(shell bc <<< "255 - $(C1)")
CMP_TOTAL	= $(shell awk -F' ' '{printf NF}' <<< "$(S) $(S_BON)")
CMP_COUNT	= $(shell ls | grep -c '\.o')

CLEAR		= "\x1b\2K\r
GREEN		= \x1b[38;2;0;255;0m
L_GREEN		= \x1b[38;2;100;255;100m
WHITE		= \x1b[0m
CMP_OK		= has been successfully compiled!                                                    \n
CMP_DELETE	= has been successfully deleted!													 \n

RBW_P1		= \x1b[38;2;$(C4);255;$(C5)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    
RBW_P2		= \x1b[38;2;255;$(C2);$(C1)m $(CMP_COUNT) / $(CMP_TOTAL) » $<                                                    


all: $(NAME)

run cg: $(NAME)
	@./$(NAME)

$(NAME): $(GB)
	@gcc -o $(NAME) main.c $(GB) $(G_FLAGS) $(CFLAGS)
	@printf "\n$(WHITE)> $(GREEN)$@ $(CMP_OK)$(WHITE)"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<
	@$(eval CMP_COUNT = $(shell expr $(CMP_COUNT) + 1))
	@if [ $(CMP_COUNT) -gt $(shell expr $(CMP_TOTAL) / 2) ]; \
		then printf $(CLEAR)>$(RBW_P1)";\
		else printf $(CLEAR)>$(RBW_P2)";\
	fi

$(GB): bg

bg:
	@make -C base_game/
	@printf "\n$(WHITE)> $(GREEN)$@ $(CMP_OK)$(WHITE)"

clean:
	@make -C base_game/ clean
	@rm -rf $(OBJ) srcs/main.o
	@printf "> $(GREEN)all .o $(CMP_DELETE)$(WHITE)"

fclean: clean
	@rm -rf $(NAME) $(GB)
	@printf "> $(GREEN)$(NAME) and $(PHY) $(CMP_DELETE)$(WHITE)"

re: fclean all

.PHONY: all bonus clean fclean re
