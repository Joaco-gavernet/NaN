string toString(__int128 num){
    string str;
    bool neg= num<0;
    do{
        int digit = num%10;
        str = to_string(abs(digit)) + str;
        num = (num - digit) / 10;
    } while(num!= 0);
    if(neg) str = "-" + str;
    return str;
}
ostream& operator<<(std::ostream& os, __int128 t){
    string str = toString(t);
    return os<< str;
}
