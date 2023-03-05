#include <arpa/inet.h>

#include "RoboCatPCH.h"

string SocketAddress::ToString() const
{
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, GetAsSockAddrIn(), ip_str, sizeof(ip_str));
    return string(ip_str);
}
