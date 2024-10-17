#pragma once
#include "Packet.h"
#include <iostream>

class PrWorldSelect : public Packet {
public:
	PrWorldSelect() : Packet(0x48B3870C) {}
	virtual void encode() {
		stream->WriteInt(0); //0 = Success
		stream->WriteBytes(( BYTES ) calloc(8, sizeof(BYTE)), 8);
		stream->WriteByte(0);
	}
};