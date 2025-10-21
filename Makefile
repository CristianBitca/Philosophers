NAME    = philo

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address -g3 -O0 -Iinc

SRC_DIR     = src/
OBJ_DIR     = obj/
INC_DIR     = inc/

SRC    = main.c \
		  philo.c \
		  procces.c \
		  utilits.c \
		  exit.c \
		  init.c \
		  monitor.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS    = $(SRC:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJECTS) -I$(INC_DIR) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)

fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run