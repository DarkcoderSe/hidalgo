bool guest_logs(char *data){
	bool val = false;
	FILE *guest_log;
	guest_log = fopen("visitors.log", "a");

	if(guest_log){
		puts(data);
		fwrite(data, sizeof(char), sizeof(data), guest_log);
		return (val=true);
	}
	else return val;
}
