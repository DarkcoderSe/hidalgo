#include "hidalga.h"
#include "config.c"
//Hidalga Server Socket MainStream
//(c) - 2018 | ALL RIGHT RESERVED

int main() {
   	int port = get_http_('P');
	int ip = get_http_('I');
   	int create_socket, new_socket;    
   	socklen_t addrlen;    
   	int bufsize = 1024;    
   	char *buffer = malloc(bufsize);    
   	struct sockaddr_in address;    
   	static char* page = 
      "HTTP/1.1 200 OK\n"
      "Content-type: text/html\n"
      "\n"
      "<html>\n"
      " <body>\n"
      "  <h1>WebPAge</h1>\n"
      "  <p>The requested URL was <?php echo'disk'; ?> on this server.</p>\n"
      " </body>\n"
      "</html>\n";
 
   if ((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0){    
      printf("The socket was created\n");
   }
    
   address.sin_family = AF_INET;    
   address.sin_addr.s_addr = INADDR_ANY;    
   address.sin_port = htons(port);    
    
   if (bind(create_socket, (struct sockaddr *) &address, sizeof(address)) == 0){    
      printf("Binding Socket\n");
   }
    
    
   while (1) {    
      if (listen(create_socket, 10) < 0) {    
         perror("server: listen");    
         exit(1);    
      }    
    
      if ((new_socket = accept(create_socket, (struct sockaddr *) &address, &addrlen)) < 0) {    
         perror("server: accept");    
         exit(1);    
      }    
    
      if (new_socket > 0){    
         printf("The Client is connected...\n");
      }
        
      recv(new_socket, buffer, bufsize, 0);    
      printf("%s\n", buffer); 
      write(new_socket, page, strlen(page));    
      close(new_socket);    
   }    
   close(create_socket);    
   return 0;    
}
