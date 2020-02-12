import time, re, math

def is_near_rep(num, PATTERN_1, PATTERN_2):
    # Regex to find near rep digit numbers
    # The first regex will find any near rep digit numbers with unique digit in middle or end
    # The second regex will find any near rep digit numbers with unique digit at first digit
    return num > 100 and (not not PATTERN_1.search(str(num)) or not not PATTERN_2.search(str(num)))

"""
The following sieve of eratosthenes is a python implementation of an
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
    PATTERN_1 = re.compile(r'^(\d)\1*?((?!\1))\d(?:\1)*?$')
    PATTERN_2 = re.compile(r'^(\d)(?!\1)(\d)(\2)+$')
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
            if sieve[n - low] and is_near_rep(n, PATTERN_1, PATTERN_2):
               found_primes.append(n)
            n += 2
    print(found_primes)
    
L1D_CACHE = int(input('Enter your CPU\'s L1D cache per core (in bytes): '))
N = input('Enter an upper limit: ')
t0 = time.time()
segmented_sieve(int(N))
t1 = time.time()
print('\nTime required:', t1 - t0)
