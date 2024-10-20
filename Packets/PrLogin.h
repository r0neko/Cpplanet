#pragma once
#include "Packet.h"
class PrLogin : public Packet {
public:
	enum LoginResponse
	{
		Success,
		Fail,
		CannotConnect,
		AlreadyConnected,
		Restricted,
		InvalidUser,
		InactiveUser,
		InternalError,
		ServerFull
	};

	PrLogin() : Packet(0x56EFE4A7) {}
	virtual void encode() {
		stream->WriteInt(LoginResponse::Success); // Response Status
		stream->WriteInt(0); // Error Code (applies only when status is InternalError)
		stream->WriteShort(0); // Restriction Reason (applies when status is Restricted)
		stream->WriteInt(0); // Restriction End Date (special formatting required for that)
		stream->WriteInt(0); // User ID (the value is using aSpecial Encryption table)
		stream->WriteString(L"eesdf"); // User Name
		stream->WriteByte(8); // Maximum allowed character slots for this account
		stream->WriteShort(0);
		stream->WriteByte(0);
		stream->WriteInt(0);
		stream->WriteByte(0);
		stream->WriteInt(0);
		stream->WriteByte(0); // If true (1) , it enforces the game to show a special dialog box before startup (results in game crashing)
		stream->WriteByte(0); // This flag may refer to NMCO authentication?

		//sub_4290C0 Start
		stream->WriteInt(0); // a parameter list array of some sort

		stream->WriteInt(0);
		stream->WriteInt(0);
		stream->WriteInt(8); // Count of existing character slots for this account

		//arrays
		stream->WriteInt(0);
		stream->WriteInt(0);
		stream->WriteInt(0);
		stream->WriteInt(0);
		stream->WriteInt(0);
		stream->WriteInt(0);
		stream->WriteInt(0);

		stream->WriteInt(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0); //1 == encode int
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);

		stream->WriteInt(0); //array
		stream->WriteInt(0); //array
		stream->WriteInt(0);
		stream->WriteInt(0); //array
		stream->WriteInt(0); //array

		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0); //some flag?
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		stream->WriteByte(0);
		//end function

		stream->WriteInt(0); // flag to request updated GSXS from server
	}
};