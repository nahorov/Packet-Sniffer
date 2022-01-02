// Created in C17, compatible with GCC 11 and above.

int main()
{
	int saddr_size, data_size;
	struct sockaddr saddr;

	unsigned char *buffer = (unsigned char *) malloc(65536);

	logfile=fopen("log.txt", "w");
	if(logfile==NULL)
	{
		printf("Unable to create log.txt file.\n");
	}

	printf("Starting...\n");
	int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	setsockopt(sock_raw, SOL_SOCKET, SO_BINDTODEVICE, "eth0", strlen("eteh0")+1);

	if(sock_raw < 0)
	{
		perror("Socket Error: ");	//Print correct error
		return 1;
	}

	while(1)
	{
		saddr_size = sizeof saddr;
		/* Receive a packet */
		data_size = recvfrom(sock_raw, buffer, 65536, 0, &saddr, (socklen_t*)&saddr_size);
		if(data_size<0)
		{
			printf("Received-from error, failed to get packets.\n");
			return 1;
		}

		//Processing the packet
		process_packet(buffer, data_size);
	}
	close(sock_raw);
	printf("Finished.\n");
	return 0;
}
