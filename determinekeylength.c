int chartoint(char c)
{
    if ('0' <= c && c <= '9') return c - '0';
    if (c >= 'A') return c - 'A' + 10;
}

void determinekeylength()
{
    unsigned char ch[2];
    double counter[256] = { 0 }; // number of times each byte appears
    FILE* fpIn;
    double N = 0; int keylength; // Possible key length from 1 to 13
    int i;
    double number = 0; // total number of characters considered
    double p[13] = { 0 }; // probability calculated for each possible keylength
    for (keylength = 1; keylength <= 13; keylength++) {
        fpIn = fopen("ctext.txt", "r"); // text form Hex
        i = 0;
        while (fscanf(fpIn, "%c", &ch[0]) != EOF) { // Hex is stored as plain text
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
        printf("%f ", p[keylength - 1]);

        fclose(fpIn);
    }
    return;
}
