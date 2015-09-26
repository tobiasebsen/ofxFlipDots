//
//  flipdots.h
//
//  Created by Tobias Ebsen on 03/06/15.
//
//

#ifndef flipdots_h
#define flipdots_h

#define FLIPDOTS_HEADER     (unsigned char)0x80
#define FLIPDOTS_END        (unsigned char)0x8F

#define FLIPDOTS_CMD_SHOW   (unsigned char)0x89
#define FLIPDOTS_CMD_DATA   (unsigned char)0x8A
#define FLIPDOTS_CMD_SPEED  (unsigned char)0x8B
#define FLIPDOTS_CMD_ADDR   (unsigned char)0x8C

#define FLIPDOTS_REQ_ADDR   (unsigned char)0xC0
#define FLIPDOTS_REQ_UPDATE (unsigned char)0x82

#define FLIPDOTS_SPEED_1200     (unsigned char)0x00
#define FLIPDOTS_SPEED_2400     (unsigned char)0x01
#define FLIPDOTS_SPEED_4800     (unsigned char)0x02
#define FLIPDOTS_SPEED_9600     (unsigned char)0x03
#define FLIPDOTS_SPEED_19200    (unsigned char)0x04
#define FLIPDOTS_SPEED_38400    (unsigned char)0x05
#define FLIPDOTS_SPEED_57600    (unsigned char)0x06
#define FLIPDOTS_SPEED_115200   (unsigned char)0x07

static unsigned int flipdots_speeds[] = {
    1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200
};

typedef struct {
    union {
        struct {
            unsigned char header;
            unsigned char command;
            unsigned char address;
            unsigned char data;
            unsigned char end;
        };
        unsigned char bytes[5];
    };
} flipdots_frame;

typedef struct {
    union {
        struct {
            unsigned char header;
            unsigned char command;
            unsigned char end;
        };
        unsigned char bytes[3];
    };
} flipdots_request;

typedef struct {
    union {
        struct {
            unsigned char first;
            unsigned char second;
            unsigned char address;
        };
        unsigned char bytes[3];
    };
} flipdots_response;

#ifdef __cplusplus
extern "C" {
#endif
    
    void flipdots_frame_init(flipdots_frame* frame, unsigned char command);
    void flipdots_request_init(flipdots_request* request, unsigned char command);
    
#ifdef __cplusplus
}
#endif

#endif
