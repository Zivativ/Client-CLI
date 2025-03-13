#include "exfiles/netlib.h"
#include "messages.h"

ip_address ip;
tcp_socket client;

void ChangeUsername(){
    Data usernamed = {0, true, 3, ""};
    char buffer[64];
    info("Enter Username: ");
    fgets(buffer, 64, stdin);
    strtok(buffer, "\n");
    sprintf_s(usernamed.data, 64,"%.64s\n", buffer);
    strtok(usernamed.data, "\n");
    info("%s\n", usernamed.data);
    netlib_tcp_send(client, &usernamed, sizeof(usernamed));
    Data data;
    netlib_tcp_recv(client, &data, sizeof(Data));
    if(data.success != TRUE){
        fail("Username was Taken! Choose Another username\n");
        ChangeUsername();
        return;
    }
}

int main(){
    if(netlib_init() < 0){
        fail("netlib_init failed: %s\n", netlib_get_error());
        return -1;
    }
    if(netlib_resolve_host(&ip, "127.0.0.1", 6942) < 0){
        fail("netlib_resolve_host failed: %s\n", netlib_get_error());
        return -1;
    }
    client = netlib_tcp_open(&ip);
    if(!client){
        fail("netlib_tcp_open failed: %s\n", netlib_get_error());
        return -1;
    }
    ChangeUsername();
    char buffer[512];
    thrd_t thread;
    if(thrd_create(&thread, ReceiveMessage, NULL) != thrd_success){
        fail("thrd_create failed\n");
        return -1;
    }
    while(1){
        fgets(buffer, 512, stdin);
        Data front = {0, true, 1, ""};
        strcpy_s(front.data, 512, buffer);
        Data back;
        netlib_tcp_send(client, &front, sizeof(front));
    }
        
    
   
    return 0;
}