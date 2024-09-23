#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b, int l) {
    if ((l % a == 0) && (l % b == 0)) {
        return l;
    } else {
        l += b;
        return lcm(a, b, l);
    }
}

int main() {
    int num1, num2, GCD, LCM;
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    GCD = gcd(num1, num2);
    LCM = lcm(num1, num2, (num1 * num2) / GCD);
    printf("GCD of %d and %d is %d\n", num1, num2, GCD);
    printf("LCM of %d and %d is %d", num1, num2, LCM);
    return 0;
}
