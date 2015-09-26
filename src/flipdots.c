//
//  flipdots.c
//
//  Created by Tobias Ebsen on 03/06/15.
//
//

#include <stdio.h>
#include "flipdots.h"

void flipdots_frame_init(flipdots_frame* frame, unsigned char command) {
    frame->header = FLIPDOTS_HEADER;
    frame->command = command;
    frame->end = FLIPDOTS_END;
}

void flipdots_request_init(flipdots_request* request, unsigned char command) {
    request->header = FLIPDOTS_HEADER;
    request->command = command;
    request->end = FLIPDOTS_END;
}