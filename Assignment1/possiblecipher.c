void possiblecipher()
{
    int i; // the ith part of the key from 0 to KEY_LENGTH - 1
    int stream; // possible ciphertext in base 10
    unsigned char ch[2];
    unsigned char c;
    int j = 0;
    int error = 0;
    for (i = 0; i != KEY_LENGTH; i++) {
        for (stream = 0; stream != 256; stream++) {
            FILE* fpIn = fopen("ctext.txt", "r");
            j = i;
            while (fscanf(fpIn, "%c", &ch[0]) != EOF) {
                fscanf(fpIn, "%c", &ch[1]);
                if (j == 0) {
                    c = 16 * chartoint(ch[0]) + chartoint(ch[1]);
                    c = c ^ stream;
                    if (c < 32 || c>127) {
                        error = 1;
                        break;
                    }
                    j = KEY_LENGTH;
                }
                j--;
            }
            if (!error) {
                printf("stream %d at %d th is possible.\n", stream, i);
            }
            fclose(fpIn);
            error = 0;
        }
    }
    return;
}
