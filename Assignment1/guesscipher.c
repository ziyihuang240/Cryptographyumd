/*
possible cipher : 
160-191 at 0
0-95    at 1
128-223 at 2
160-191 at 3
0-95    at 4
128-223 at 5
32-63   at 6
*/ 

void guesscipher() {
    int i = 3;    //guess the ith key
    int j;
    FILE* fpIn;
    unsigned char ch[2];
    unsigned char c;
    double N = 0;
    int stream;
    double sum = 0;
    double q[26] = {0.082,0.015,0.028,0.043,0.127,0.022,0.02,0.061,0.07,0.003,0.018,0.04,0.024,0.067,0.075,0.019,0.001,0.06,0.063,0.091,0.028,0.01,0.024,0.003,0.02,0.001}; // frequency for lowercase english letters, taken from Wikipedia
    for (stream = 160; stream <= 191; stream++) // stream range is determined by the remark in the first few lines.
    {
        sum = 0;
        N = 0;
        double p[26] = { 0 }; // lower case letters
        fpIn = fopen("ctext.txt", "r");
        j = i;
        while (fscanf(fpIn, "%c", &ch[0]) != EOF) {
            fscanf(fpIn, "%c", &ch[1]);
            if (j == 0) {
                N++;
                c = 16 * chartoint(ch[0]) + chartoint(ch[1]);
                c = c ^ stream;
                if ('a' <= c && c <= 'z') {
                    p[c - 'a']++;
                }
                j = KEY_LENGTH;
            }
            j--;
        }
        fclose(fpIn);
        for (int k = 0; k != 26; k++) {
            sum += (p[k] / N) * q[k];
        }
        printf("stream %d gives sum %f\n", stream, sum); // We should then try the biggest sum closest to 0.065.
    }
    return;
}
