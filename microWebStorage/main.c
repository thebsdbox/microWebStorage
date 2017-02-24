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
    printf("microWebServer Starting...\n");
    start_tcp();
    return 0;
}
