#include "hidalga.h"
#include "config.c"
#include "log_generator.c"
#include "http_request.c"

//Hidalgo Server Socket MainStream
//(c) - 2018 | ALL RIGHT RESERVED

int main() {
   	int port = get_http_(Hid_Port);
	int ip = get_http_(Hid_IP);
   	int create_socket, new_socket;    
   	socklen_t addrlen;

   	int bufsize = 1024;    
   	char *buffer = malloc(bufsize);    
   	struct sockaddr_in address;    
   	
 
   	if ((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0){    
   	   printf("The socket was created\n");
   	}
    
   	address.sin_family = AF_INET;    
   	address.sin_addr.s_addr = INADDR_ANY;    
   	address.sin_port = htons(port);    
    
   	if (bind(create_socket, (struct sockaddr *) &address, sizeof(address)) == 0){    
   	   printf("Binding Socket\n");
   	}
    
    signal(SIGINT, INThandler);
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
       //printf("%s\n", buffer);
	   if(guest_logs(buffer) == true) printf("\nLogs Saved\n");
	   else printf("\nLog Writing Err :: log_generator.c\n");
		
	   printf("\n---->\n");
		char *page = request_handler(true);
       write(new_socket, page, strlen(page));    
       close(new_socket);
   }
    
   close(create_socket);    
   return 0;    
}
