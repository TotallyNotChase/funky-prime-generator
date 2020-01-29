import numpy as np
import time

def uniqnum(num):
    unique_set = {}
    for num in str(num):
        if unique_set.get(num):
            unique_set[num] += 1
        else:
            unique_set[num] = 1
    return unique_set

def isPrime(n) : 
    # Corner cases 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True

num = 1

near_rep_primes = []
N = int(input("Enter upper limit: "))
now = time.time()
for num in range(101, N + 1, 2):
    uniq_set = uniqnum(num)
    if len(uniq_set) == 2 and ((list(uniq_set.values())[0] >= 2 and list(uniq_set.values())[1] == 1) or 
                               (list(uniq_set.values())[1] >= 2 and list(uniq_set.values())[0] == 1)):
        if isPrime(num):
            near_rep_primes.append(num)
print(near_rep_primes)
print("Took", str(time.time() - now))
