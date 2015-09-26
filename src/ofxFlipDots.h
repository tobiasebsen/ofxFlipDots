//
//  ofxFlipDots.h
//
//  Created by Tobias Ebsen on 03/06/15.
//
//

#pragma once

#include "ofMain.h"
#include "flipdots.h"

namespace ofxFlipDots {

    class Frame : public flipdots_frame {
    public:
        Frame(uint8_t cmd);

        void setAddress(uint8_t address);
        void setData(uint8_t data);
        
        inline operator unsigned char * () { return this->bytes; }
    };
    
    template<uint8_t CMD>
    class _Frame : public Frame {
    public:
        _Frame() : Frame(CMD) {}
    };
    
    typedef _Frame<FLIPDOTS_CMD_SHOW> FrameShow;
    typedef _Frame<FLIPDOTS_CMD_DATA> FrameData;
    typedef _Frame<FLIPDOTS_CMD_SPEED> FrameSpeed;
    typedef _Frame<FLIPDOTS_CMD_ADDR> FrameAddress;
    
    class Request : public flipdots_request {
    public:
        Request(uint8_t cmd);
        
        inline operator unsigned char * () { return this->bytes; }
    };
    
    template<uint8_t CMD>
    class _Request : public Request {
    public:
        _Request() : Request(CMD) {}
    };
    
    typedef _Request<FLIPDOTS_REQ_ADDR> RequestAddress;
    typedef _Request<FLIPDOTS_REQ_UPDATE> RequestUpdate;
    
    class ResponseAddress : public flipdots_response {
    public:
        uint8_t getAddress();
    };
}
