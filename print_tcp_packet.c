// Created in C17, and compatible with GCC 11 and above
// Code to print the contents of the TCP Packet to the log file

void print_tcp_packet(unsigned char* Buffer, int Size)
{
    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr*)(Buffer + sizeof(struct ethhdr));
    iphdrlen = iph->ihl*4;

    struct tcphdr *tcph=(struct tcphdr*)(Buffer + iphdrlen + sizeof(struct ethhdr));
    int header_size = sizeof(struct ethhdr) + iphdrlen + tcph->doff*4;
    fprintf(logfile, "\n\n\t\t---TCP Packet---\t\t\n\n");
    print_ip_header(Buffer, Size);

    /* TCP Header Contents */
    fprintf(logfile, "\n");
    fprintf(logfile, "TCP Header\n");
    fprintf(logfile, " |-Source Port            : %u\n", ntohs(tcph->source));
    fprintf(logfile, " |-Destination Port       : %u\n", ntohs(tcph->dest));
    fprintf(logfile, " |-Sequence Number        : %u\n", ntohl(tcph->seq));
    fprintf(logfile, " |-Acknowledgement Number : %u\n", ntohl(tcph->ack_seq));
    fprintf(logfile, " |-Header Legnth          : %d dwords or %d bytes\n", (unsigned int)tcph->doff, (unsigned int)tcph->doff*4);
    /* fprintf(logfile, " |-CWR Flag               : %d\n", (unsigned int)tcph->cwr);
    fprintf(logfile, " |-ECN Flag               : %d\n", (unsigned int)tcph->ece); */
    fprintf(logfile, " |-Urgent Flag            : %d\n", (unsigned int)tcph->urg);
    fprintf(logfile, " |-Acknowledgement Flag   : %d\n", (unsigned int)tcph->ack);
    fprintf(logfile, " |-Push Flag              : %d\n", (unsigned int)tcph->psh);
    fprintf(logfile, " |-Reset Flag             : %d\n", (unsigned int)tcph->rst);
    fprintf(logfile, " |-Synchronize Flag       : %d\n", (unsigned int)tcph->syn);
    fprintf(logfile, " |-Finish Flag            : %d\n", (unsigned int)tcph->fin);
    fprintf(logfile, " |-Window                 : %d\n", (unsigned int)tcph->window);
    fprintf(logfile, " |-Checksum               : %d\n", (unsigned int)tcph->check);
    fprintf(logfile, " |-Urgent Pointer         : %d\n", (unsigned int)tcph->urg_ptr);
    fprintf(logfile, " \n");
    fprintf(logfile, "\t\t\t DATA DUMP \t\t\t\n");
    fprintf(logfile, " \n");

    /* IP Header contents */
    fprintf(logfile, "IP Header");
    print_data(Buffer, iphdrlen);

    fprintf(logfile, "TCP Header\n");
    print_data(Buffer+iphdrlen,tcph->doff*4);

    fprintf(logfile, "\n############################################################\n");
}
