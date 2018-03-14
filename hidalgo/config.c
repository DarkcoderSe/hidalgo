#define CHUNK 50

int get_http_(char match){
	
	char port[CHUNK], read, *line=NULL;
	FILE *http_port_fd;
	size_t len;
	int xport;

    http_port_fd = fopen("conf/http.conf", "r");
	if (http_port_fd) {
    	while ((read = getline(&line, &len, http_port_fd)) != -1){
			if(line[0] != '$'){
				if(line[0] == match){
					xport = get_integerFs(line);
					printf("SET :: %s", line);
					return xport;
				}
			}
		}

    	if (ferror(http_port_fd)){
			printf("\n$ Configuration file error\n"); 
		}
	    fclose(http_port_fd);
	}
}
int get_integerFs(char *line){
	int num=0;
	int count=0;
	int i=0;

	while (sscanf(line, "%*[^0-9]%d%n", &num, &i)==1){
    	line+=i;
    	count++;
	}
	return num;
}
