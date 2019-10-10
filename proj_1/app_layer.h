#pragma once

#define CTRL_SIZE_I 0
#define CTRL_NAME_I 1

#define TLV_PACKETS_COUNT 2
#define TLV_SIZE_T 0
#define TLV_NAME_T 1

#define DATA_BYTES 10

int send_file(char * filename, int fd);

typedef enum{
    CTRL_DATA = 1,
    CTRL_START = 2,
    CTRL_END = 3
} app_ctrl_field;

typedef struct{
    unsigned char type;
    unsigned char length;
    unsigned char * value;
} tlv_packet;

typedef struct{
    char c_field; /* Control field. 2 - start, 3 - end */
    unsigned char tlv_count; /* Number of tlv packets included */
    tlv_packet * tlv_packets;
} app_ctrl_packet;

typedef struct{
    char c_field;
    unsigned char seq_n;
    unsigned char byte_n_l;
    unsigned char byte_n_h;
    unsigned char * data;
} app_data_packet;
