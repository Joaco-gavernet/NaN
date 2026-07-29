string toString(__int128 num) {
    string str;
    do {
        int digit = num % 10;
        str = to_string(digit) + str;
        num = (num - digit) / 10;
    } while (num != 0);
    return str;
}
ostream& operator<<(std::ostream& os, __int128 t) {
    string str = toString(t);
    return os << str;
}
