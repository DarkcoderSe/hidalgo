bool ls_htdocs(char *file){
	bool ans=false;
	char *line=NULL;
	size_t len;
	system("cd htdocs && ls > htdocs.log");
	FILE *htdocs;
	htdocs = fopen("htdocs/htdocs.log", "r");
	if(htdocs){
		while ((getline(&line, &len, htdocs)) != -1){
			printf("|line::%s|Argu::%s|", line, file);
			if(strcmp(line, file)==0){
				return (ans=true);	
			}else{
				return ans;		
			}
		}
	}
}
char* request_handler(bool req){
	
	static char* OK = 
      "HTTP/1.1 200 OK\n"
      "Content-type: text/html\n\n";
	//strcat(index, OK);
	static char* NOT = 
      "HTTP/1.1 404 NOT FOUND\n"
      "Content-type: text/html\n\n"
      "<html>"
      " <body>"
      "  <h1>Error 404</h1>"
      "  <p>The requested URL is not on this server.</p>"
      " </body>"
      "</html>";
	
	if(req == true){
		return OK;
	}
	else{
		return NOT;	
	}
}
