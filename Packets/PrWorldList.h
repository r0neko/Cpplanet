#pragma once
#include "Packet.h"
class PrWorldList : public Packet {
public:
	PrWorldList() : Packet(0x4128264E) {}
	virtual void encode() {
		stream->WriteInt(6);
		for (int i = 0; i < 6; i++) {
			stream->WriteShort(0);
			stream->WriteString(L"이시프");
			stream->WriteShort(0);
			stream->WriteByte(0);
			stream->WriteByte(0);
		}
	}
};