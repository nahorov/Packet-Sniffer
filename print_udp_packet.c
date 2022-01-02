// Created in C17, and compatible with GNU GCC 11 and above.
// Code to print the contents of the UDP packet to the log file

void print_udp_packet(unsigned char *Buffer, int Size)
{
    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)(Buffer + sizeof(struct ethhdr));
    iphdrlen = iph->ihl*4;

    struct udphdr *udph = (struct udphdr*)(Buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size = sizeof(struct ethhdr) + iphdrlen + sizeof udph;

    fprintf(logfile, "\n\n\t\t ---UDP Packet--- \t\t\n");
    print_ip_header(Buffer, Size);

    fprintf(logfile, "\nUDP Header\n");
    fprintf(logfile, " |-Source Port            : %d\n", ntohs(udph->source));
    fprintf(logfile, " |-Destination Port       : %d\n", ntohs(udph->dest));
    fprintf(logfile, " |-UDP Length             : %d\n", ntohs(udph->len));
    fprintf(logfile, " |-UDP Checksum           : %d\n", ntohs(udph->check));
    fprintf(logfile, "\n");
    fprintf(logfile, "\nIP Header\n");
    print_data(Buffer, iphdrlen);

    fprintf(logfile, "\n");
    fprintf(logfile, "UDP Header\n");
    print_data(Buffer+iphdrlen, sizeof udph);

    fprintf(logfile, "Data Payload\n");

    /* Move the pointer ahead and reduce the size of the string */
    print_data(Buffer + header_size, Size - header_size);

    fprintf(logfile, "\n########################################################\n");
}
