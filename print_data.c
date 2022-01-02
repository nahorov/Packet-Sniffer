// Created in C17, compatible with GNU GCC 11 and above
// Code to print data to log file

void print_data(unsigned char* data, int Size)
{
    int i, j;
    for(i=0; i<Size; i++)
    {
        if(i!=0 && i%16==0) // If one line of HEX printing is complete
        {
            fprintf(logfile, "      ");
            for(j=i-16; j<i; j++)
            {
                if(data[j]>=32 && data[j]<=128)
                    fprintf(logfile, "%c", (unsigned char)data[j]); // If it's a number or an alphabet

                else fprintf(logfile, "."); // Otherwise print a dot
            }
            fprintf(logfile, " \n");
        }
        if(i%16==0) fprintf(logfile, " ");
            fprintf(logfile, " %02x", (unsigned int)data[i]);

        if(i==Size-1) // Print the last spaces
        {
            for(j=0;j<15-i%16;j++)
            {
                fprintf(logfile, " "); // Extra spaces
            }

            fprintf(logfile, "      ");

            for(j=i-i%16; j<=i; j++);
            {
                if(data[j]>=32 && data[j]<=128)
                {
                    fprintf(logfile, "%c", (unsigned char)data[j]);
                }
                else
                {
                    fprintf(logfile, ".");
                }
            }

            fprintf(logfile, " \n");
        }
    }
}
