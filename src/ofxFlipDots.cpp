//
//  ofxFlipDots.cpp
//
//  Created by Tobias Ebsen on 03/06/15.
//
//

#include "ofxFlipDots.h"

using namespace ofxFlipDots;

Frame::Frame(uint8_t command) {
    flipdots_frame_init(this, command);
}

void Frame::setAddress(uint8_t address) {
    flipdots_frame::address = address;
}

void Frame::setData(uint8_t data) {
    flipdots_frame::data = data;
}

Request::Request(uint8_t command) {
    flipdots_request_init(this, command);
}

uint8_t ResponseAddress::getAddress() {
    return flipdots_response::address;
}