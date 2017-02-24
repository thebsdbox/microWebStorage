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
#include "mwsHTTPD.h"

int main(int argc, const char * argv[]) {
    printf("microWebStorage Starting...\n");
    
    // Set a port to bind to
    setPort(8888);
    // create a socket
    createINETSocket();
    // bind to that socket
    bindToINETSocketWithPort();
    // start listening on that socket
    startListener();
    // create listening loop to process incoming packets
    startListenLoop();
    return 0;
}
