#include "exfiles/netlib.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>
ip_address ip;
tcp_socket client;

typedef struct _Data {
    int version;
    char data[512];
    bool success;
} Data;

DWORD WINAPI ReceiveMessage(void* data){

    Data datas;
    while(1){
        netlib_tcp_recv(client, &datas, sizeof(datas));
        printf("Server - %s\n", datas.data);
        sprintf(datas.data, "");
        Sleep(1000);
    }
    
}
int main(){
    if(netlib_init() < 0){
        printf("netlib_init failed: %s\n", netlib_get_error());
        return -1;
    }
    if(netlib_resolve_host(&ip, "127.0.0.1", 6942) < 0){
        printf("netlib_resolve_host failed: %s\n", netlib_get_error());
        return -1;
    }
    client = netlib_tcp_open(&ip);
    if(!client){
        printf("netlib_tcp_open failed: %s\n", netlib_get_error());
        return -1;
    }\
    char buffer[512];
    CreateThread(NULL, 0, ReceiveMessage, NULL, 0, 0);
    while(1){
        fgets(buffer, 512, stdin);
        Data front = {0, "", true};
        strcpy_s(front.data, 512, buffer);
        Data back;
        netlib_tcp_send(client, &front, sizeof(front));
        netlib_tcp_recv(client, &back, sizeof(back));
        //printf("Data Received!\n VERSION = %d - DATA = %s - SUCCESS = %d\n", back.version, back.data, back.success);
    }
        
    
   
    return 0;
}