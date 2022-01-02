#include"headers.h"
#include"main.c"
#include"process_packet.c"
#include"print_ethernet_header.c"
#include"print_ip_header.c"
#include"print_tcp_packet.c"
#include"print_udp_packet.c"
#include"print_icmp_packet.c"
#include"print_data.c"

int main();
void process_packet(unsigned char* buffer, int size);
void print_ethernet_header(unsigned char* Buffer, int size);
void print_ip_header(unsigned char* Buffer, int size);
void print_tcp_packet(unsigned char* Buffer, int Size);
void print_udp_packet(unsigned char *Buffer, int Size);
void print_icmp_packet(unsigned char* Buffer, int Size);
void print_data(unsigned char* data, int Size);
