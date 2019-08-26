SRCS = /srcs/*.c
INCLUDES = /includes/*.h

all:
gcc -Wall -Werror -Werror $(SRCS) -I $(INCLUDES) -o base
clean: 
