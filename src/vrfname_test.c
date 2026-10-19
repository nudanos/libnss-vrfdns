/*
 * get_vrfname: the VRF whose hosts and resolver configuration an NSS lookup
 * uses: VYATTA_VRF_NSS_HOSTS, else VYATTA_VRF, else "default".
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nss_vrfdns.h"

static int check(const char *want)
{
	const char *got = get_vrfname();

	if (got == NULL || strcmp(got, want) != 0) {
		fprintf(stderr, "get_vrfname: got %s, want %s\n", got ? got : "NULL", want);
		return 1;
	}
	return 0;
}

int main(void)
{
	int failed = 0;

	unsetenv("VYATTA_VRF_NSS_HOSTS");
	unsetenv("VYATTA_VRF");
	failed |= check("default");
	setenv("VYATTA_VRF", "blue", 1);
	failed |= check("blue");
	setenv("VYATTA_VRF_NSS_HOSTS", "red", 1);
	failed |= check("red");
	if (!failed)
		printf("vrfname_test: OK\n");
	return failed;
}
