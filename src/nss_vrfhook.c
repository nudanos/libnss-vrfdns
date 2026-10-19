/*
 * Copyright (c) 2016 by Brocade Communications Systems, Inc.
 * All rights reserved.
 */

#include <stdlib.h>
#include "nss_vrfdns.h"

/*
 * The VRF of this lookup. A pointer into the environment, or "default":
 * nothing to free, and never NULL (it used to strdup, and every caller's
 * strcmp crashed if that failed).
 */
const char *get_vrfname(void)
{
    const char *vrfname = getenv("VYATTA_VRF_NSS_HOSTS");

    if (!vrfname)
        vrfname = getenv("VYATTA_VRF");

    if (!vrfname)
        return "default";

    return vrfname;
}
