#include "SmartInStream.h"
#include "../Logger.h"
SmartInStream::SmartInStream(BYTES payload, int length) {
	buffer = payload;
	this->length = length;
	offset = 0;
}
bool SmartInStream::checkForLength(int len) {
	if (offset + len <= length) {
		return true;
	}
	Logger::Warn(L"SmartInStream::checkForLength에서 false를 반환했습니다. 길이 %d, 오프셋 %d", len, offset);
	return false;
}
BYTE SmartInStream::ReadByte() {
	if(checkForLength(1)){
		return buffer[ offset++ ];
	}
	return 0xFF;
}
short SmartInStream::ReadShort() {
	return ( ReadByte() | ( ReadByte() << 8 ) );
}
int SmartInStream::ReadInt() {
	return ( ReadByte() | ( ReadByte() << 8 ) | ( ReadByte() << 16 ) | ( ReadByte() << 24 ) );
}
BYTES SmartInStream::ReadBytes(int len) {
	if ( checkForLength(len) ) {
		BYTES buf = ( BYTES ) malloc(len);
		memcpy(buf, buffer + offset, len);
		offset += len;
		return buf;
	}
	return nullptr;
}