NAME = test_matrix_lib

SRCS	= vector.c \
			test_vector.c \
			# matrix.c
HEADERS	= $(patsubst %.c,%.h,$(SRCS))
OBJDIR	= obj
OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

clean:
	$(RM) -r $(NAME).dSYM
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

show:
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all clean fclean re show
