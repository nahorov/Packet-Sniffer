// Created in C17, and compatible with GNU GCC 11 and above
// Code to process the incoming packet

void process_packet(unsigned char* buffer, int size)
{
	//Get the IP header part of the packet, exclude the Ethernet header.
	struct iphdr *iph = (struct iphdr*)(buffer + sizeof(struct ethhdr));
	++total;

	switch(iph->protocol) //Check the protocol and act accordingly
	{
		case 1: //ICMP protocol
			++icmp;
			print_icmp_packet(buffer, size);
			break;

		case 2: //IGMP protocol
			++igmp;
			break;

		case 6: //TCP protocol
			++tcp;
			print_tcp_packet(buffer, size);
			break;

		case 17: //UDP protocol
			++udp;
			print_udp_packet(buffer, size);
			break;

		default: //Miscellaneous protocols
			++others;
			break;
	}
	printf("TCP: %d\n UDP: %d/n ICMP: %d\n IGMP: %d\n Others: %d\n Total: %d\r \n", tcp, udp, icmp, igmp, others, total);
}
