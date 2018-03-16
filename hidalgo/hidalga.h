#include<netinet/in.h>    
#include<stdio.h>    
#include<stdlib.h>    
#include<sys/socket.h>    
#include<sys/stat.h>    
#include<sys/types.h>    
#include<unistd.h>    
#include<string.h>
#include<stdbool.h>
#include<signal.h>

#define Hid_Port 'P'
#define Hid_IP 'I'
int get_integerFs(char *line, int num, int count);
void INThandler(int);
