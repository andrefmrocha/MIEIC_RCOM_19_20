#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ll.h"
#include "serial_driver.h"

static link_layer layer;
static bool sequence_number = true;

int llopen(int port, connection_role role) {
  sprintf(layer.port, "/dev/ttyS%d", port);
  layer.baud_rate = BAUDRATE;
  layer.num_transmissions = 3;
  layer.timeout = 3;
  int fd = open_connection(layer);
  if (fd != -1) {
    switch (role) {
      case TRANSMITTER:
        set_connection(layer);
        break;
      case RECEIVER:
        acknowledge_connection();
    }
  }
  return fd;
}

int llwrite(int fd, char *buffer, int length) {
  int written_bytes = write_data(fd, sequence_number, buffer, length);
  if (written_bytes != -1)
    sequence_number = !sequence_number;
  return written_bytes;
}

int llread(int fd, char *buffer) {
  int buffer_length = read_data(fd, sequence_number, buffer);
  if (buffer_length > 0)
    sequence_number = !sequence_number;
  return buffer_length;
}

int llclose(int fd) {
  return close_connection(fd);
}