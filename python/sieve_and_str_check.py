import time, math

def is_glitch(num):
    # Check if the number is a glitch number
    numstr = str(num)
    if len(numstr) < 3:
        # Glitch numbers must be at least 3 digits
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

# The whole segmented sieve approach is nothing interesting
# Tt's just a standard approach

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
            if is_glitch(p):
                print(p, end = ' ')
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
            if mark[i - low] and is_glitch(i): 
                print(i, end = ' ') 
        low = low + segmented_lim 
        high = high + segmented_lim 
  
t0 = time.time()
N = input('Enter an upper limit: ')
segmented_sieve(int(N))
t1 = time.time()
print('\nTime required:', t1 - t0)
