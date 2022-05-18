CC =				clang
NAME_CLIENT	=		client
NAME_SERVER =		server
SRCS_NAME_CLIENT =	client.c
SRCS_NAME_SERVER =	server.c

SRCS_CLIENT =		$(addprefix $(SRCS_PATH)/, $(SRCS_NAME_CLIENT))
SRCS_SERVER =		$(addprefix $(SRCS_PATH)/, $(SRCS_NAME_SERVER))	

SRCS_PATH =			srcs
INC_NAME =			minitalk.h \
INC =				$(addprefix $(INC_PATH)/, $(INC_NAME))
INC_PATH =			includes
INC_PATH_LIBFT = 	libft/includes
RM =				rm -rf
OBJ_CLIENT =		$(SRCS_CLIENT:.c=.o)
OBJ_SERVER =		$(SRCS_SERVER:.c=.o)
CFLAG =				-Wall -Wextra -Werror
INCFLAGS =			-I$(INC_PATH_LIBFT) -I$(INC_PATH)
LIBFT =				libft/libft.a
LIBFT_PATH =		./libft

all :				 $(NAME_CLIENT) $(NAME_SERVER)

%.o : %.c
					$(CC) $(CFLAG) $(INCFLAGS) -c $< -o $@

$(NAME_CLIENT) : 	$(OBJ_CLIENT) $(INC)
					make -C $(LIBFT_PATH)
					$(CC) -o $@ $(OBJ_CLIENT) $(LIBFT)

$(NAME_SERVER) :	$(OBJ_SERVER) $(INC)
					make -C $(LIBFT_PATH)
					$(CC) -o $@ $(OBJ_SERVER) $(LIBFT)

clean :
					make clean -C $(LIBFT_PATH)
					$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean :			clean
					make fclean -C $(LIBFT_PATH)
					$(RM) $(NAME_CLIENT) $(NAME_SERVER) 

re : 				fclean all

.PHONY : 			all clean fclean re
