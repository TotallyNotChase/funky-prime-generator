#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

int size = 5;
int current_slot = 0;
int *primes_arr;

void append(int data)
{
    if ((current_slot + 1) < size)
    {
        primes_arr[current_slot++] = data;
        return;
    }
    int* newarr = realloc(primes_arr, (size+=5) * sizeof(int));
    if (newarr != NULL)
    {
        newarr[current_slot++] = data;
        primes_arr = newarr;
    }
    else
    {
        printf("\nAn error occured while re-allocating memory\n");
        exit(1);
    }
}

bool isNearRep(int num)
{
    int i, unqcharcount = 0;
    char str[100], commonchar;      // The str can hold a max of 100 digits - change if needed
    snprintf(str, 100, "%d", num);  // Converting the integer number to a string
    if (strlen(str) < 3)
    {
        // Near Rep numbers should be at least 3 digits
        return false;
    }
    /**
    * Find the common character in the first few digits
    *  i.e if we feed in 9999899, the common char is 9
    */
    if (str[0] == str[1] || str[0] == str[2])
    {
        commonchar = str[0];
    }
    else if (str[1] == str[2])
    {
        commonchar = str[1];
    }
    else
    {
        // if no common character is found i.e 968999 or 988999
        return false;
    }
    /** 
    * The above conditional statements will still find a common char
    * even if the number is 99986574, this is why we loop through for
    * additional checks
    */
    for (i = 0; i < strlen(str); i += 1)
    {
        // Checks for multiple unique digits i.e digits that are not common digits
        if (str[i] != commonchar)
        {
            unqcharcount++;
        }
        if (unqcharcount > 1)
        {
            break;
        }
    }
    if (unqcharcount == 1)
    {
        // Must have exactly one unique digit
        return true;
    }
    else
    {
        return false;
    }
}

// The following is just a standard approach to segmented sieve, nothing interesting

void simpleSieve(int limit)
{
    int p;
    if (primes_arr == NULL)
    {
        printf("\nAn error occured while allocating primes_arr for mark in simpleSieve\n");
        exit(1);
    }
    bool* mark = malloc((limit + 1) * sizeof(bool));
    if (mark != NULL)
    {
        memset(mark, true, sizeof(bool) * (limit + 1));
    }
    else
    {
        printf("\nAn error occured while allocating memory for mark in simpleSieve\n");
        exit(1);
    }

    for (p = 2; p * p < limit; p++)
    {
        if (mark[p])
        {
            for (int i = p * 2; i < limit; i += p)
            {
                mark[i] = false;
            }
        }
    }

    for (p = 2; p < limit; p++)
    {
        if (mark[p])
        {
            append(p);
            if (isNearRep(p))
            {
                printf("%d ", p);
            }
        }
    }
}

void segmentedSieve(int n)
{
    int limit = (int)floor(sqrt(n)) + 1;
    simpleSieve(limit);

    int low = limit;
    int high = 2 * limit;

    while (low < n)
    {
        if (high >= n)
        {
            high = n;
        }
        bool* mark = malloc((limit + 1) * sizeof(bool));
        if (mark != NULL)
        {
            memset(mark, true, sizeof(bool) * (limit + 1));
        }
        else
        {
            printf("\nAn error occured while allocating memory for mark in segmentedSieve\n");
            exit(1);
        }
        for (int i = 0; i < current_slot; i++)
        {
            int lower_lim = (int)floor(low / primes_arr[i]) * primes_arr[i];
            if (lower_lim < low)
            {
                lower_lim += primes_arr[i];
            }
            for (int j = lower_lim; j < high; j += primes_arr[i])
            {
                mark[j - low] = false;
            }
        }

        for (int i = low; i < high; i++)
        {
            if (mark[i - low] == true && isNearRep(i))
            {
                printf("%d ", i);
            }
        }
        low = low + limit;
        high = high + limit;
        free(mark);
    }
}

int main()
{
    int N;
    double time_taken;
    primes_arr = malloc(size * sizeof(int));
    printf("Enter upper limit: ");
    scanf_s("%d", &N);
    clock_t begin = clock();
    segmentedSieve(N);
    clock_t end = clock();
    time_taken = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nDone! Exectuion time: %f\n", time_taken);
    return 0;
}
