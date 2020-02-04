#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<time.h>

/**
* The following sieve of eratosthenes is a C implementation of an
* improved sieve of eratosthenes algorithm written by Kim Wilsch in C++
* ///////////////////////////////////////////////////////////////////////
* COPYRIGHT NOTICE:-
* BSD 2-Clause License
*
* Copyright (c) 2010 - 2019, Kim Walisch.
* All rights reserved.
* ///////////////////////////////////////////////////////////////////////
* Apart from the algorithm idea itself, everything else is written by
* [https://github.com/TotallyNotChase]
*/

typedef struct uint64_vector
{
    uint64_t* data;
    uint64_t capacity, size;
} uint64vec_t;

typedef struct char_vector
{
    bool* data;
    uint64_t size, count;
} boolvec_t;

uint64_t L1D_CACHE;

uint64vec_t create_uint64_vector(uint64_t size)
{
    uint64vec_t vector;
    vector.data = malloc(size * sizeof(uint64_t));
    if (vector.data == NULL)
    {
        printf("\nAn error occured while allocating memory for uint64_vector\n");
        exit(1);
    }
    vector.capacity = size;
    vector.size = 0;
    return vector;
}

boolvec_t create_bool_vector(uint64_t size)
{
    boolvec_t vector;
    vector.data = malloc(size * sizeof(bool));
    if (vector.data == NULL)
    {
        printf("\nAn error occured while allocating memory for bool_vector\n");
        exit(1);
    }
    memset(vector.data, true, sizeof(bool) * size);
    vector.size = size;
    vector.count = 0;
    return vector;
}

void uint64_vector_append(uint64vec_t* vector, uint64_t data)
{
    if ((vector->size + 1) < vector->capacity)
    {
        vector->data[vector->size++] = data;
        return;
    }
    vector->data = realloc(vector->data, (vector->capacity *= 2) * sizeof(uint64_t));
    if (vector->data == NULL)
    {
        printf("\nAn error occured while re-allocating memory for uint64_vector\n");
        exit(1);
    }
}

int countDigits(uint64_t num)
{
    return snprintf(NULL, 0, "%" SCNu64, num) - (num < 0);
}

bool isNearRep(uint64_t num)
{
    int i, unqcharcount = 0, digitcount = countDigits(num);
    char* str, commonchar;
    str = malloc((digitcount + 1) * sizeof(char));
    snprintf(str, digitcount + 1, "%" SCNu64, num);    // Converting the integer number to a string
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

size_t approximate_size(uint64_t limit)
{
    int i;
    float x = 1;
    for (i = log(limit); i > 0; i--)
    {
        x *= 2.5;
    }
    return (size_t) x;
}

void segmented_sieve(uint64_t limit)
{
    int64_t low, high, i = 3, j, k, n = 3, s = 3;
    size_t i_size, approx_arr_size = approximate_size(limit);
    uint64_t sqrtval = (uint64_t)sqrt(limit);
    uint64_t segment_size = sqrtval < L1D_CACHE ? L1D_CACHE : sqrtval;
    uint64vec_t prime_arr = create_uint64_vector(approx_arr_size);
    uint64vec_t multiples = create_uint64_vector(approx_arr_size);
    boolvec_t sieve = create_bool_vector(segment_size);
    boolvec_t is_prime = create_bool_vector(sqrtval + 1);
    for (low = 0; low <= limit; low += segment_size)
    {
        memset(sieve.data, true, sizeof(bool) * sieve.size);
        high = low + segment_size - 1;
        high = high < limit ? high : limit;
        for (; i * i <= high; i += 2)
        {
            if (is_prime.data[i])
            {
                for (j = i * i; j <= sqrtval; j += i)
                {
                    is_prime.data[j] = false;
                }
            }
        }
        for (; s * s <= high; s += 2)
        {
            if (is_prime.data[s])
            {
                uint64_vector_append(&prime_arr, s);
                uint64_vector_append(&multiples, s * s - low);
            }
        }
        for (i_size = 0; i_size < prime_arr.size; i_size++)
        {
            j = multiples.data[i_size];
            for (k = prime_arr.data[i_size] * 2; j < segment_size; j += k)
            {
                sieve.data[j] = false;
            }
            multiples.data[i_size] = j - segment_size;
        }
        for (; n <= high; n += 2)
        {
            if (sieve.data[n - low] && isNearRep(n))
            {
                printf("%" SCNu64 ", ", n);
            }
        }
    }
}

int main()
{
    uint64_t N;
    double time_taken;
    printf("Enter your CPUs L1D Cache per core (in bytes): ");
    scanf_s("%" SCNu64, &L1D_CACHE);
    printf("Enter upper limit: ");
    scanf_s("%" SCNu64, &N);
    clock_t begin = clock();
    printf("[");
    segmented_sieve(N);
    printf("\b\b]");
    clock_t end = clock();
    time_taken = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nDone! Exectuion time: %f\n", time_taken);
    return 0;
}