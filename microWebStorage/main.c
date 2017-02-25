/* main.c
 *
 * microWebStorage
 *
 * Copyright (C) 2017 <Daniel Finneran, dan@thebsdbox.co.uk >
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the GPL license.  See the LICENSE file for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include "mwsHTTPD.h"

int main(int argc, const char * argv[]) {
    printf("microWebStorage Starting...\n");
    
    char *tcpPort = getenv("mwsPort");
    char *contentType = getenv("mwsContentType");
    if (tcpPort) {
        // Set a port to bind to
        size_t port = atoi(tcpPort);
        setPort(port);
        
        if (contentType) {
            setContentType(contentType);
        }
        // create a socket
        createINETSocket();
        // bind to that socket
        bindToINETSocketWithPort();
        // start listening on that socket
        startListener();
        // create listening loop to process incoming packets
        startListenLoop();
        return 0;
    } else {
        printf("[Error] Please set environment varialbe mwsPort\n");
        printf("microWebStorage Exiting...\n");

        return -1;
    }
    
    return 0;
}
