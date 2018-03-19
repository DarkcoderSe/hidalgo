bool guest_logs(char *data){
	bool val = false;
	FILE *guest_log;
	guest_log = fopen("visitors.log", "a");

	if(guest_log){
		//puts(data);
		fputs(data, guest_log);
		//fwrite(data, sizeof(char), sizeof(data), guest_log);
		return (val=true);
	}
	else return val;
}
void INThandler(int sig){
    char c;
	
    signal(sig, SIG_IGN);
    printf("\nOUCH, did you hit Ctrl-C?\n"
            "Do you really want to quit? [y/n] ");
    c = getchar();
    if (c == 'y' || c == 'Y')
         exit(0);
    else
         signal(SIGINT, INThandler);
    getchar();
}
