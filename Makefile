
CLIENT = client.c helper_functions.c
CLIENT_BIN = client
SRV = server.c helper_functions.c
SRV_BIN = server

LIB = libft.a
CPPFLAGS = -I. -I./libft/includes -L./libft 
HEADERS = minitalk.h ./libft/includes/libft.h
CCFLAGS = -Wall -Werror -Wextra
LFLAGS = -l:$(LIB)



all : $(LIB) client server 


client:	$(CLIENT:.c=.o) $(HEADERS)
		$(CC) $(CPPFLAGS) $(CCFLAGS) $(CLIENT) -o $(CLIENT_BIN) $(LFLAGS)

server:	$(SRV:.c=.o) $(HEADERS) 
		$(CC) $(CPPFLAGS) $(CCFLAGS) $(SRV) -o $(SRV_BIN) $(LFLAGS)

%.o: 	%.c $(HEADERS) $(LIB)
		$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@

$(LIB) :
		make -C ./libft all

clean:
		rm -rf $(CLIENT:.c=.o) $(SRV:.c=.o)
		make -C ./libft clean

fclean: clean
		rm -rf $(CLIENT_BIN) $(SRV_BIN)
		make -C ./libft fclean

re: fclean all