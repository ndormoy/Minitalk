SRCS_BASE =		is/ft_isalpha.c \
				is/ft_isdigit.c \
				is/ft_isalnum.c \
				is/ft_isascii.c \
				is/ft_isprint.c \
				is/ft_toupper.c \
				is/ft_tolower.c \
				memory/ft_memset.c \
				memory/ft_bzero.c \
				memory/ft_calloc.c \
				memory/ft_memchr.c \
				memory/ft_memcmp.c \
				memory/ft_memcpy.c \
				memory/ft_memmove.c \
				strings/ft_split.c \
				strings/ft_strchr.c \
				strings/ft_strdup.c \
				strings/ft_striteri.c \
				strings/ft_strjoin.c \
				strings/ft_strlcpy.c \
				strings/ft_strlcat.c \
				strings/ft_strlen.c \
				strings/ft_strmapi.c \
				strings/ft_strncmp.c \
				strings/ft_strrchr.c \
				strings/ft_substr.c \
				strings/ft_strtrim.c \
				strings/ft_strnstr.c \
				transform/ft_atoi.c \
				transform/ft_itoa.c \
				put/ft_putchar_fd.c \
				put/ft_putstr_fd.c \
				put/ft_putendl_fd.c \
				put/ft_putnbr_fd.c \
				lst/ft_lstnew.c \
				lst/ft_lstadd_front.c \
				lst/ft_lstsize.c \
				lst/ft_lstlast.c \
				lst/ft_lstadd_back.c \
				lst/ft_lstdelone.c \
				lst/ft_lstclear.c \
				lst/ft_lstiter.c \
				lst/ft_lstmap.c
SRCS_GNL =		gnl/get_next_line_utils.c \
				gnl/get_next_line.c
SRCS_PRINTF =	printf/ft_itoa.c \
				printf/ft_print_p.c \
				printf/ft_printf.c \
				printf/ft_utils_unsigned_int.c \
				printf/ft_utils.c \
				printf/ft_print_type.c \
				printf/ft_print_hexa.c

CC =			clang
NAME =			libft.a
SRCS =			$(addprefix $(SRCS_PATH)/, $(SRCS_BASE) $(SRCS_GNL) $(SRCS_PRINTF))
SRCS_PATH =		srcs
INC_NAME =		libft.h \
				get_next_line.h
INC =			$(addprefix $(INC_PATH)/, $(INC_NAME))
INC_PATH =		includes
RM =			rm -rf
OBJ =			$(SRCS:.c=.o)
CFLAG =			-Wall -Wextra -Werror
INCFLAGS =		-I$(INC_PATH)

all :		 	$(NAME)

%.o : %.c
				$(CC) $(CFLAG) $(INCFLAGS) -c $< -o $@

$(NAME) : 		$(OBJ) $(INC)
				ar rcs $@ $(OBJ)

clean :
				$(RM) $(OBJ)

fclean :		clean
				$(RM) $(NAME)

re : 			fclean all

.PHONY : 		all clean fclean re bonus
