CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
TARGET = libft.a

SRCDIR = srcs
INCDIR = includes

SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)

$(TARGET): $(OBJS)
	ar cr $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
