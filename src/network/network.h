#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED






#include "../superheader.h"





int SetupNetworking();
ip_address ReturnIP();
tcp_socket ReturnSocket();
int ChangeUsername(char* name);
char* ReturnUsername();
int ChangeIPAddress(char* ip);
char* ReturnIpAddress();
int LoginToServer();
char* ReturnList();
void ChangeList(char* list);
#endif