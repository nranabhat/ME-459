#include <stdio.h>
#include <math.h>

float g(float x) {
    return sin(x) / x;
}

int main() {
    float a = 0.0, b = 1.0;
    float tol = 1e-7;
    float c;
    
    while (b - a > tol) {
        c = (a + b) / 2.0;
        if (g(c) < 1.0) {
            b = c;
        } else {
            a = c;
        }
    }

    float xd = (a + b) / 2.0;
    printf("xf = %.20f\n", xd);
    
    return 0;
}
