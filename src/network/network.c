#include "network.h"
#include <string.h>





static ip_address ip;
static tcp_socket sock;
static char username[64];
static char ipaddress[512];

static char chatlist[UINT16_MAX];

int SetupNetworking(){
    netlib_init();
    if(netlib_resolve_host(&ip, ipaddress, 6942) < 0){
        return -1;
    }
    sock = netlib_tcp_open(&ip);
    if(!sock){
        return -2;
    }
    
    return 0;
}

int LoginToServer(){
    int result = SetupNetworking();
    if(result != 0) return result;
    result = netlib_tcp_send(ReturnSocket(), username, strlen(username));
    if(result < strlen(username)){
        printf("Hi, Result is %d\n", result);
        return -3;
    } 
    result = netlib_tcp_recv(ReturnSocket(), chatlist, UINT16_MAX);
    if(result <= 0){
        printf("Hi\n");
        return -4;
    } 
    if(chatlist[0] != ';') return 1;
    return 0;
}

ip_address ReturnIP(){
    return ip;
}



tcp_socket ReturnSocket(){
    return sock;
}


int ChangeUsername(char* name){
    if(strlen(name) >= 64){
        return -1;
    }
    sprintf(username, "");
    sprintf(username, "%s", name);
    return 0;
}


char* ReturnUsername(){
    return username;
}



int ChangeIPAddress(char* ip){
    if(strlen(ip) >= 512){
        return -1;
    }
    sprintf(ipaddress, "");
    sprintf(ipaddress, "%s", ip);
    return 0;
}


char* ReturnIpAddress(){
    return ipaddress;
}

char* ReturnList(){
    return chatlist;
}

void ChangeList(char* list){
    sprintf(chatlist, "");
    sprintf(chatlist, "%s", list);
}