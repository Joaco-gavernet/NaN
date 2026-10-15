// 3 ^ n iteration
forn(mask, (1<<n)){
    int sm = 0;
    do {
        // do something with submask
    } while (sm=(sm-mask)&mask);
}
