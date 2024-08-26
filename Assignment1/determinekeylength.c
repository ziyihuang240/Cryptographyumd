int chartoint(char c)
{
    if ('0' <= c && c <= '9') return c - '0';
    if (c >= 'A') return c - 'A' + 10;
}

void determinekeylength()
{
    int keylength;// Possible key length from 1 to 13
for (keylength = 5; keylength <= 20; keylength++) {
    unsigned char ch[2];
    double counter[256] = { 0 }; // each byte
    FILE* fpIn;
    double N = 0;
    int i;
    double number = 0; // number of characters chosen
    double p[20] = { 0 };
    fpIn = fopen("ctext.txt", "r"); // text form Hex
    i = 0;
    while (fscanf(fpIn, "%c", &ch[0]) != EOF) {
        fscanf(fpIn, "%c", &ch[1]);
        if (N == 0) {
            i = 16 * chartoint(ch[0]) + chartoint(ch[1]);
            number++;
            counter[i]++;
            N = keylength;
        }
        N--;
    }
    for (i = 0; i != 256; i++)
    {
        p[keylength - 1] += (counter[i] * counter[i]) / (number * number);
    }
    printf("Keylength %d gives %f\n", keylength, p[keylength - 1]);

    fclose(fpIn);
}
return;
}
