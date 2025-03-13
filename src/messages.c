#include "messages.h"




extern tcp_socket client;


static inline void PrintMessage(Data* datas){
    printf("%s\n", datas->data);
    sprintf(datas->data, "");
    //Sleep(100);
    //thrd_sleep()
}


static inline void PrintErrorMessage(Data* datas){
    char buffer[1024];
    sprintf(buffer, "Server - %s\n", datas->data);
    printf("%s\n", buffer);
    sprintf(datas->data, "");
    //Sleep(1000);
}

int ReceiveMessage(void* data){
    info("NEW THREAD TYPE CREATED\n");
    Data datas;
    while(1){
        CONTINUE:
        int rec = netlib_tcp_recv(client, &datas, sizeof(datas));
        if(rec <= 0){
            info("The Server Closed\n");
            exit(0);
        } 
        switch(datas.type){
            case 0:
                PrintMessage(&datas);
                goto CONTINUE;
            case 2:
                PrintErrorMessage(&datas);
                break;
            default:
                printf("UNKNOWN TYPE, SKIPPING..\n");
                goto CONTINUE;;
        }
        
    }
}

// int ReceiveMessage(void* data){

// }