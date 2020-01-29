import time, re, math

def is_near_rep(num):
    # Regex to find near rep digit numbers
    # The first regex will find any near rep digit numbers with unique digit in middle or end
    # The second regex will find any near rep digit numbers with unique digit at first digit
    return num > 100 and (not not re.search(r'^(\d)\1*?((?!\1))\d(?:\1)*?$', str(num)) or not not re.search(r'^(\d)(?!\1)(\d)(\2)+$', str(num)))

# The whole segmented sieve approach is nothing interesting
# It's just a standard approach

def simple_sieve(limit): 
    primes_list = [] 
    mark = [True for i in range(limit + 1)] 
    p = 2
    while (p * p <= limit): 
        if (mark[p] == True):  
            for i in range(p * p, limit + 1, p):  
                mark[i] = False  
        p += 1
    for p in range(2, limit):  
        if mark[p]: 
            primes_list.append(p)
            if is_near_rep(p):
                near_rep_primes.append(p)
    return primes_list

def segmented_sieve(n): 
    segmented_lim = int(math.floor(math.sqrt(n)) + 1) 
    primes_list = simple_sieve(segmented_lim)
    low = segmented_lim 
    high = segmented_lim * 2
    while low < n:
        if high >= n:
            high = n
        mark = [True for i in range(segmented_lim + 1)]
        for i in range(len(primes_list)):
            lower_lim = int(math.floor(low / primes_list[i]) * 
                                         primes_list[i]) 
            if lower_lim < low: 
                lower_lim += primes_list[i] 
            for j in range(lower_lim, high, primes_list[i]): 
                mark[j - low] = False
        for i in range(low, high): 
            if mark[i - low] and is_near_rep(i): 
                near_rep_primes.append(i)
        low = low + segmented_lim 
        high = high + segmented_lim 

near_rep_primes = []
N = input('Enter an upper limit: ')
t0 = time.time()
segmented_sieve(int(N))
print(near_rep_primes)
t1 = time.time()
print('\nTime required:', t1 - t0)
