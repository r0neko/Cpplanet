#pragma once
#include "Packet.h"
class PrAuthLogin : public Packet {
public:
	PrAuthLogin() : Packet(0x403FD53F) {}
	virtual void encode() {
		stream->WriteByte(1); //success
		stream->WriteBytes(( BYTES ) calloc(11, sizeof(BYTE)), 11);
	}
}; 