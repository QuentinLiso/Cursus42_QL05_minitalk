
SRC_FOLD = ./srcs/
CLIENT = $(addprefix $(SRC_FOLD), client.c helper_functions.c)
CLIENT_BIN = client
SRV = $(addprefix $(SRC_FOLD), server.c helper_functions.c)
SRV_BIN = server

LIB_A = libft.a
LIB_DIR = ./libft/
LIB = $(LIB_DIR)$(LIB_A)

HEADERS_FOLD = includes
CPPFLAGS = -I./$(HEADERS_FOLD) -I$(LIB_DIR)/$(HEADERS_FOLD) 
HEADERS = ./$(HEADERS_FOLD)/minitalk.h ./$(LIB_DIR)/$(HEADERS_FOLD)/libft.h

CCFLAGS = -Wall -Werror -Wextra
LFLAGS = -L$(LIB_DIR) -l:$(LIB_A)

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