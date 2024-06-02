#include "system.h"
#include "../utils/lazy_import.h"
#include "../utils/crypt/crypt.h"
std::string System::GetHwid(){
	HW_PROFILE_INFO hwProfile;
	
	if(!GetCurrentHwProfileA(&hwProfile)){
		return "ERROR";
	}
	const char* szGuid = hwProfile.szHwProfileGuid;
	const char* pc_name = getenv(xorstr("COMPUTERNAME"));
	const char* processor_rev = getenv(xorstr("PROCESSOR_REVISION"));

	std::string hwid = std::string(szGuid) + std::string(pc_name) + std::string(processor_rev);
	int  hwid_to_int;
	for(int i = 0; i < hwid.size(); i++)
		hwid_to_int+= static_cast<int>(hwid[i]) * hwid.size();
	return encode(std::to_string(hwid_to_int).c_str());
}

std::string System::Web::Get(const char* ip,const char* name,int port){
	WORD dllVer = MAKEWORD(2,1);
	WSAData data;
	WSAStartup(dllVer,&data);


	SOCKET socket_client  = socket(AF_INET,SOCK_STREAM,0);

	
	SOCKADDR_IN  addres_client;

	memset(&addres_client,0,sizeof(SOCKADDR_IN));

	
	//My ip settings
	addres_client.sin_family = AF_INET;
	addres_client.sin_port = htons(port);
	addres_client.sin_addr.S_un.S_addr =  inet_addr(ip);
	
	//Connect in Addres 
	int conn = connect(socket_client,(struct sockaddr*)&addres_client,sizeof(addres_client));

	//Sleep send message
	Sleep(700);

	std::string message_buffer  = xorstr("GET /").decrypt() + std::string(name) + xorstr("HTTP/1.1\r\nHost: ").decrypt() + std::string(ip) + xorstr("\r\nConnection: close\r\n\r\n").decrypt();
	send(socket_client,message_buffer.c_str(),strlen(message_buffer.c_str()),0);

	char buffer[1024];

	recv(socket_client,buffer,sizeof(buffer),0);

	//Close Addres
	shutdown(socket_client,1);

	WSACleanup();
	closesocket(socket_client);
	
	return buffer;
}


std::string System::Web::DecodeRequest(std::string req) {
	bool isHttp = false;
	std::string new_string;
	for(int i = 0;i < req.size();i++){
		
		if(req.at(i) == '8'){
			i+= 5;
			isHttp = !isHttp;
		}
			
		
		if(isHttp)
			new_string += req.at(i);
	}
	return new_string;
}


std::string System::File::ReadString(const char* name){
	FILE* file = fopen(name,"r");

	fseek(file,0,SEEK_END);
	int size = ftell(file);
	rewind(file);
	char* buffer = (char*)malloc(size + 1);
	
	fread(buffer,1,size,file);
	fclose(file);

	std::string readBuffer = buffer;
	free(buffer);
	return readBuffer;
}

bool System::File::IsFile(const char* nameFile){
	FILE* file = fopen(nameFile,"r");
	if(!file)
		return 0;
		
	fclose(file);
	return 1;
}