while (<>) {
    s/(()()/$1/g;
    print;
}