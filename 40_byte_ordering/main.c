#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// The byte ordering on the CPU is different than the byte ordering
// in network packets
// see 'man byteorder' for the functions in the arpa/inet.h file
// that provide host-to-network and network-to-host helpers

int main(void) {
    uint16_t a = 0xeffa;
    uint32_t b = 0xeffabedc;

    printf("a: %x\n", a);
    printf("b: %x\n", b);

    // Print out the actual bytes as represented on the CPU
    // If it is little endian it will print 'faef'
    printf(
        "a: %x%x\n",
        ((uint8_t*)&a)[0],
        ((uint8_t*)&a)[1]
    );

    // Same thing as before, but with 32 bit
    printf(
        "b: %x%x%x%x\n",
        ((uint8_t*)&b)[0],
        ((uint8_t*)&b)[1],
        ((uint8_t*)&b)[2],
        ((uint8_t*)&b)[3]
    );

    a = htons(a);
    printf(
        "host-to-network a: %x%x\n",
        ((uint8_t*)&a)[0],
        ((uint8_t*)&a)[1]
    );

    b = htonl(b);
    printf(
        "host-to-network b: %x%x%x%x\n",
        ((uint8_t*)&b)[0],
        ((uint8_t*)&b)[1],
        ((uint8_t*)&b)[2],
        ((uint8_t*)&b)[3]
    );

    return 0;
}
