// Created in C17, compatible with GNU GCC 11 and above.
// This is a compilation of all the header files that are going to be required, pre-declaration of functions
// and variables that are to be used globally by all the functions that comprise this program. */

#include<netinet/in.h>
#include<errno.h>
#include<netdb.h>
#include<stdio.h>               //Standard C input-output
#include<stdlib.h>              //Memory Allocation
#include<string.h>              //String functions

#include<netinet/ip_icmp.h>     //Provides declarations for ICMP header
#include<netinet/udp.h>         //Provides declarations for UDP header
#include<netinet/tcp.h>         //Provides declarations for TCP header
#include<netinet/ip.h>          //Provides declarations for IP header
#include<netinet/if_ether.h>	//For ETH_P_ALL
#include<net/ethernet.h>        //For ether_header
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<unistd.h>

void process_packet(unsigned char*, int);
void print_ip_header(unsigned char*, int);
void print_tcp_packet(unsigned char*, int);
void print_udp_packet(unsigned char*, int);
void print_icmp_packet(unsigned char*, int);
void print_data(unsigned char*, int);

FILE *logfile;
struct sockaddr_in source, destination;
int tcp=0, udp=0, icmp=0, others=0, igmp=0, total=0, i, j;
