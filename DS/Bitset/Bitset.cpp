
void solve()
{
    bitset <5> a("11010");
    bitset <5> b(14);
    cout<<b<<" is b\n";
    for(int i=4;i>=0;i--) cout<<b[i]<<" \n"[i]; // prints b (loop have to be reversed)
    cout<<b.count()<<" set bits\n"; // counts set bits in b

    b.set(); // sets all bits to 1 (11111)
    b.reset(); // resets all bits to 0(00000)
    b.flip(); // flips all bits (11111)

    bitset <3> b8(8); // overflow (b = 000)
    bitset<5> c(10); // (01010)
    c<<=1; // (10100)
    c>>=2; // (00101)
    c &= 6; // (00100)
    c |= 10; // (01110)
    c = ~c; // (10001)
    c ^= 5; // (10100)
    bitset<5> d(12); // (01100)
    c |= d; // (11100)
    cout<<c.to_string()<<" is c in string\n";
    cout<<c.to_ullong()<<" is c in unsigned long long\n";

    for(int i=c._Find_first();i<c.size();i=c._Find_next(i)) cout<<i<<' ';
    cout<<" are set bits in c\n";

    if(c.all()) cout<<"all are set in c\n";
    if(c.any()) cout<<"c has atleast one set bit\n";

}