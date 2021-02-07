#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i;
struct hostent *he;
struct in_addr **addr_list;
struct in_addr addr;

// get the addresses of www.yahoo.com:

he = gethostbyname("www.google.com");
if (he == NULL) { // do some error checking
    herror("gethostbyname"); // herror(), NOT perror()
}

// print information about this host:
printf("Official name is: %s\n", he->h_name);
printf("IP address: %s\n", inet_ntoa(*(struct in_addr*)he->h_addr));
printf("All addresses: ");
addr_list = (struct in_addr **)he->h_addr_list;
for(i = 0; addr_list[i] != NULL; i++) {
    printf("%s ", inet_ntoa(*addr_list[i]));
}
printf("\n");

// get the host name of 66.94.230.32:

inet_aton("66.94.230.32", &addr);
he = gethostbyaddr(&addr, sizeof(addr), AF_INET);

printf("Host name: %s\n", he->h_name);
    return 0;
}
