#pragma once

#include <stdint.h>

int stuff_buffer(unsigned char *buffer, int length);

int destuff_buffer(unsigned char *buffer, int length);

int parse_arguments(int argc, char *argv[]);

unsigned char byte_size(long num);

long file_size(char *filename);

int frame_cmp(unsigned char *p1, unsigned char *p2);

unsigned char *frame_cpy(unsigned char *dest, unsigned char *src);

void send_non_info_frame(int fd, unsigned char control_field);
