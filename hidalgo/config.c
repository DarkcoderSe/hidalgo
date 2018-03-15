#define CHUNK 50
#define HTTP_conf "conf/http.conf"

int get_http_(char match){
	
	char port[CHUNK], read, *line=NULL;
	FILE *http_port_fd;
	size_t len;
	int xport;

    http_port_fd = fopen(HTTP_conf, "r");
	if (http_port_fd) {
    	while ((read = getline(&line, &len, http_port_fd)) != -1){
			if(line[0] != '$'){
				if(line[0] == match){
					xport = get_integerFs(line, 0, 0);
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
int get_integerFs(char *line, int num, int count){
	int i=0;

	while (sscanf(line, "%*[^0-9]%d%n", &num, &i)==1){
    	line+=i;
    	count++;
	}
	return num;
}
