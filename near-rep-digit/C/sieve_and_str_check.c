#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

unsigned int size = 5, current_slot = 0;
unsigned long long* primes_arr;

void append(unsigned long long data)
{
    if ((current_slot + 1) < size)
    {
        primes_arr[current_slot++] = data;
        return;
    }
    unsigned long long* newarr = realloc(primes_arr, (size += 5) * sizeof(unsigned long long));
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

int countDigits(unsigned long long num)
{
    return snprintf(NULL, 0, "%llu", num) - (num < 0);
}

bool isNearRep(unsigned long long num)
{
    int i, unqcharcount = 0, digitcount = countDigits(num);
    char* str, commonchar;
    str = malloc((digitcount + 1) * sizeof(char));
    snprintf(str, digitcount + 1, "%llu", num);    // Converting the integer number to a string
    if (digitcount < 3)
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

void simpleSieve(unsigned long long limit)
{
    unsigned long long p;
    if (primes_arr == NULL)
    {
        printf("\nAn error occured while allocating primes_arr for mark in simpleSieve\n");
        exit(1);
    }
    bool* mark = malloc((limit + 1ll) * sizeof(bool));
    if (mark == NULL)
    {
        printf("\nAn error occured while allocating memory for mark in segmentedSieve\n");
        exit(1);
    }
    memset(mark, true, sizeof(bool) * (limit + 1ll));

    for (p = 2; p * p < limit; p++)
    {
        if (mark[p])
        {
            for (unsigned long long i = p * 2; i < limit; i += p)
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
                printf("%llu, ", p);
            }
        }
    }
}

void segmentedSieve(unsigned long long n)
{
    unsigned long long limit = (unsigned long long)floor(sqrt(n)) + 1ll;
    simpleSieve(limit);

    unsigned long long low = limit;
    unsigned long long high = 2 * limit;

    while (low < n)
    {
        if (high >= n)
        {
            high = n;
        }
        bool* mark = malloc((limit + 1ll) * sizeof(bool));
        if (mark == NULL)
        {
            printf("\nAn error occured while allocating memory for mark in segmentedSieve\n");
            exit(1);
        }
        memset(mark, true, sizeof(bool) * (limit + 1ll));

        for (unsigned long long i = 0; i < current_slot; i++)
        {
            unsigned long long lower_lim = (unsigned long long)floor(low / primes_arr[i]) * primes_arr[i];
            if (lower_lim < low)
            {
                lower_lim += primes_arr[i];
            }
            for (unsigned long long j = lower_lim; j < high; j += primes_arr[i])
            {
                mark[j - low] = false;
            }
        }

        for (unsigned long long i = low; i < high; i++)
        {
            if (mark[i - low] && isNearRep(i))
            {
                printf("%llu, ", i);
            }
        }
        low = low + limit;
        high = high + limit;
        free(mark);
    }
}

int main()
{
    unsigned long long N;
    double time_taken;
    primes_arr = malloc(size * sizeof(unsigned long long));
    printf("Enter upper limit: ");
    scanf_s("%llu", &N);
    clock_t begin = clock();
    printf("[");
    segmentedSieve(N);
    printf("\b\b]");
    clock_t end = clock();
    time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nDone! Exectuion time: %f\n", time_taken);
    return 0;
}