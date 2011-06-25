#include "serialization/header.h"
#include "types/ys/theader.cpp"
#include <string.h>

/* I don't put thin function in the struct
   to ensure C compatibility
   and because of memory avarice.

   We work with pointer because when you put
   a truct in argument of a function, a copy of the values is made
   which is a waste of time.

   The hton/ntoh (host to network / network to host) ensure the endianess compatibility.
   Eg my Intel Core I3 is big indian whereas my Intel Dual Core is little indian
*/


void packtheader(int size, int kind, char* buffer)
{
    theader header;
    header.size = size;
    header.kind = kind;
    //htontheader(&header);
    memcpy(buffer, (char *)&header, 8);
}

theader unpacktheader(char* buffer)
{
    theader header;
    memcpy((char*)&header,buffer,8);
    //ntohtheader(&header);
    return header;
}

