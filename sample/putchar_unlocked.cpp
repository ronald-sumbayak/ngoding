void unlocked_output (int n, char separator = '') {
    char op[20], ln = 0;
    while (n != 0) op[ln++] = (n % 10) + '0', n /= 10;
    for (int i = ln-1; i >= 0; i--) putchar_unlocked (op[i]);
    putchar_unlocked (separator);
}

int main () {
    unlocked_output (5);
}