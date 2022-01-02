// Created in C17, and compatible with GNU GCC 11 and above
// Code to print the contents of the ICMP Packet to the logfile

void print_icmp_packet(unsigned char* Buffer, int Size)
{
    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)(Buffer + sizeof(struct ethhdr));
    iphdrlen = iph->ihl*4;

    struct icmphdr *icmph = (struct icmphdr *)(Buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size = sizeof(struct ethhdr) + iphdrlen + sizeof icmph;

    fprintf(logfile, "\n\t\t---ICMP Packet---\t\t\n");
    print_ip_header(Buffer, Size);
    fprintf(logfile, " \n");

    fprintf(logfile, "ICMP Header\n");
    fprintf(logfile, " |-Type                   : %d", (unsigned int)(icmph->type));

    if((unsigned int)(icmph->type)==11)
    {
        fprintf(logfile, "TTL Expired\n");
    }
    else if((unsigned int)(icmph->type) == ICMP_ECHOREPLY)
    {
        fprintf(logfile, "ICMP Echo Reply\n");
    }

    fprintf(logfile, " |-Code                   : %d\n", (unsigned int)(icmph->code));
    fprintf(logfile, " |-Checksum               : %d\n", ntohs(icmph->checksum));
    /* fprintf(logfile, " |-ID                     : %d\n", ntohs(icmph->id));
    fprintf(logfile, " |-Sequence               : %d\n", ntohs(icmph->sequence)); */
    fprintf(logfile, " \n");

    fprintf(logfile, "IP Header\n");
    print_data(Buffer, iphdrlen);

    fprintf(logfile, "UDP Header\n");
    print_data(Buffer + iphdrlen, sizeof icmph);

    fprintf(logfile, "Data Payload\n");

    /* Move the pointer ahead and reduce the size of the string */
    print_data(Buffer + header_size, (Size - header_size));

    fprintf(logfile, "\n############################################################\n");
}
