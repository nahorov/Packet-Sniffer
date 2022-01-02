// Created in C17, and compatible with GNU GCC 11 and above.
// Code to print the contents of the IP Header into the logfile

void print_ip_header(unsigned char* Buffer, int size)
{
    print_ethernet_header(Buffer, size);
    unsigned short iphdrlen;

    struct iphdr *iph = (struct iphdr *)(Buffer + sizeof(struct ethhdr));
    iphdrlen=iph->ihl*4;

    memset(&source, 0, sizeof(source));
    source.sin_addr.s_addr=iph->saddr;

    memset(&destination, 0, sizeof(source));
    destination.sin_addr.s_addr = iph->daddr;

    fprintf(logfile, " \n");
    fprintf(logfile, "IP Header\n");
    fprintf(logfile, " |-IP Version             : %d\n", (unsigned int)iph->version);
    fprintf(logfile, " |-IP Header Length       : %d DWORDS or %d bytes\n", (unsigned int)iph->ihl, ((unsigned int)(iph->ihl))*4);
    fprintf(logfile, " |-Type of Service        : %d\n", (unsigned int)iph->tos);
    fprintf(logfile, " |-IP Total Length        : %d bytes(size of packet)\n", ntohs(iph->tot_len));
    fprintf(logfile, " |-Identification         : %d\n", ntohs(iph->id));
    /*fprintf(logfile, " |-Reserved ZERO field    : %d\n", (unsigned int)iph->ip_reserved_zero);
    fprintf(logfile, " |-Don't fragment field   : %d\n", (unsigned int)iph->ip_dont_fragment);
    fprintf(logfile, " |-More fragment field    : %d\n", (unsigned int)iph->ip_more_fragment); */
    fprintf(logfile, " |-TTL                    : %d\n", (unsigned int)iph->ttl);
    fprintf(logfile, " |-Protocol               : %d\n", (unsigned int)iph->protocol);
    fprintf(logfile, " |-Checksum               : %d\n", ntohs(iph->check));
    fprintf(logfile, " |-Source IP              : %s\n", inet_ntoa(source.sin_addr));
    fprintf(logfile, " |-Destination IP         : %s\n", inet_ntoa(destination.sin_addr));

}
