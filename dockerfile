FROM gcc:4.9
COPY . /packet-sniffer
WORKDIR /packet-sniffer/
RUN gcc packet_sniffer_master.c -o packet-sniffer
CMD ["./packet-sniffer"]
