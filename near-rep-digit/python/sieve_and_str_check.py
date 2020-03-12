import time, math

def is_near_rep(num):
    # Check if the number is a near rep digit number
    numstr = str(num)
    if len(numstr) < 3:
        # Near rep digit numbers must be at least 3 digits
        return False
    """
      Find the common character in the first few digits
      i.e if we feed in 9999899, the common char is 9
    """
    if numstr[0] == numstr[1] or numstr[0] == numstr[2]:
        commonchar = numstr[0]
    elif numstr[1] == numstr[2]:
        commonchar = numstr[1];
    else:
        # If no common character is found
        # i.e 968999 or 988999
        return False
    """
      The above conditional statements will still find a common char
      even if the number is 99986574, this is why we loop through for
      additional checks
    """
    unqcharcount = 0
    for i in numstr:
    # Checks for multiple unique digits
    # i.e digits that are not common digits
        if i != commonchar:
            unqcharcount += 1
        if unqcharcount > 1:
            break
    if unqcharcount == 1:
        # Must have exactly one unique digit
        return True
    else:
        return False

"""
The following sieve of eratosthenes is a C implementation of an
improved sieve of eratosthenes algorithm written by Kim Wilsch in C++
"""

# COPYRIGHT NOTICE:-
# BSD 2-Clause License
#
# Copyright (c) 2010 - 2019, Kim Walisch.
# All rights reserved.

"""
Apart from the algorithm idea itself, everything else is written by
[https://github.com/TotallyNotChase]
"""

def segmented_sieve(limit):
    i, n, s = 3, 3, 3
    sqrtval = int(math.sqrt(limit))
    segment_size = sqrtval if sqrtval > L1D_CACHE else L1D_CACHE
    is_prime = [True for x in range(0, sqrtval + 1)]
    prime_arr = []
    multiples = []
    found_primes = []
    for low in range(0, limit + 1, segment_size):
        sieve = [True for x in range(0, segment_size)]
        high = low + segment_size - 1
        high = high if high < limit else limit
        while i * i <= high:
            if is_prime[i]:
                for j in range(i * i, sqrtval + 1, i):
                    is_prime[j] = False
            i += 2
        while s * s <= high:
            if is_prime[s]:
                prime_arr.append(s)
                multiples.append(s * s - low)
            s += 2
        for i_size in range(0, len(prime_arr)):
            k = prime_arr[i_size] * 2
            j = multiples[i_size]
            while j < segment_size:
                sieve[j] = False
                j += k
            multiples[i_size] = j - segment_size
        while n <= high:
            if sieve[n - low] and is_near_rep(n):
               found_primes.append(n)
            n += 2
    print(found_primes)

L1D_CACHE = int(input('Enter your CPU\'s L1D cache per core (in bytes): '))
N = input('Enter an upper limit: ')
t0 = time.time()
segmented_sieve(int(N))
t1 = time.time()
print('\nTime required:', t1 - t0)
