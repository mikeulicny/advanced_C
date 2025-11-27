#include <stdio.h>
#include <complex.h>

// 'man tgmath.h' to see type generic math
#include <tgmath.h>

// Compile this with the following
// gcc -Wall -Wextra -lm -std=c99

// Just a helper function to print complex numbers
char *cfmt(double complex z) {
    static char buf[256] = {0};
    double real = creal(z);
    double imag = cimag(z);
    int write_size = 0;
    if (real != 0) {
        write_size = sprintf(buf, "%.1f", real);
        if (imag != 0)
            write_size += sprintf(buf + write_size, " + ");
    }
    if (imag != 0)
        sprintf(buf + write_size, "%.1fi", imag);
    return buf;
}


int main(void) {

    // To use complex types: your type, then 'complex'
    double complex z = 2 + 3*I;
    printf("z = %s\n", cfmt(z));
    printf("z_r = %.1f\n", creal(z));   // just get real part
    printf("z_i = %.1f\n", cimag(z));   // just get complex part
    
    // Handles all your complex math
    double complex z2 = 4 + 9*I;
    printf("z + z2 = %s\n", cfmt(z + z2));
    printf("z * z2 = %s\n", cfmt(z * z2));
    printf("\n");
    printf("cabs(z) = %.1f\n", cabs(z));
    printf("csin(z) = %s\n", cfmt(csin(z)));
    printf("ccos(z) = %s\n", cfmt(cos(z))); // We use tgmath here, cos() is a macro that adapts
    printf("\n");
    printf("i   = %s\n", cfmt(I));
    printf("i^2 = %s\n", cfmt(I * I));
    printf("i^3 = %s\n", cfmt(I * I * I));
    printf("i^4 = %s\n", cfmt(I * I * I * I));

    return 0;
}
