#pragma once

#include <stdint.h>

#define CTRL_SIZE_I 0
#define CTRL_NAME_I 1

#define TLV_PACKETS_COUNT 2
#define TLV_SIZE_T 0
#define TLV_NAME_T 1

#define DATA_BYTES 200
#define MAX_FRAME_SIZE ((1 << 16) - 1 + 4) // USHORT_MAX + 4

#define MAX_FILENAME_SIZE 1024

typedef enum{
    CTRL_DATA = 1,
    CTRL_START = 2,
    CTRL_END = 3
} app_ctrl_field;

typedef struct{
    uint8_t type;
    uint8_t length;
    uint8_t * value;
} tlv_packet;

typedef struct{
    char c_field; /* Control field. 2 - start, 3 - end */
    uint8_t tlv_count; /* Number of tlv packets included */
    tlv_packet * tlv_packets;
} app_ctrl_packet;

typedef struct{
    char c_field;
    uint8_t seq_n;
    uint8_t byte_n_low;
    uint8_t byte_n_high;
    uint8_t * data;
} app_data_packet;

typedef struct{
    char * filename;
    long filesize;
} ctrl_info;

/*typedef enum {
    START_STATE = 0,
    DATA_STATE,
    END_STATE,
    FINAL_STATE
} al_state_machine;
*/

typedef enum {
    PROGRESS_BAR_SEND,
    PROGRESS_BAR_RECEIVE
} al_progress_bar;

int send_file(char * filename, int fd);

int read_file(int fd, char * filename);