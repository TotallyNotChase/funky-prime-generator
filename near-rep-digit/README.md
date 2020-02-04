# Methods
* `non_sieve_and_unique_set` : It uses a prime check approach and then a **set comprehension** to check if the prime number is also a near rep digit prime. Written by [Max Bridgland](https://github.com/M4cs)
* `sieve_and_str_check` : It uses an improved segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then a **string comprehension** to check if the prime number is also a near rep digit prime. This is the *fastest* method here. Written by [TotallyNotChase](https://github.com/TotallyNotChase)
* `sieve_and_regex` : It uses an improved segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then 2 **regex expressions** to check if the prime number is also a near rep digit prime. This is the *second fastest* method here. Written by [TotallyNotChase](https://github.com/TotallyNotChase)

# Usage
**Makes sure to use the programs in 64 bit if you plan to compute bigger numbers**
**Also make sure to provide your CPU's Level 1 Data Cache if asked, this must be *per core* and *in bytes*. Search [wikichip](https://en.wikichip.org/wiki/WikiChip) with your cpu entry**

* `non_sieve_and_unique_set.py` : Simply run `python non_sieve_and_unique_set.py` or `python3 non_sieve_and_unique_set`
* `sieve_and_str_check.py` : Simply run `python sieve_and_str_check.py` or `python3 sieve_and_str_check`
* `sieve_and_regex.py` : Simply run `python sieve_and_str_check.py` or `python3 sieve_and_str_check`
* `sieve_and_str_check.c` : You can either compile using `MSVC` or `clang` and run the generated executable file - **Must be compiled in 64 bit**

# SPEEEEED!

Here's some benchmarks, This is the *best time* I found running on **my PC**. `N` (upper limit) is 10,000,000 (10M).

The `python` script for `non_sieve_and_unique_set` completes in **12.8 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73342220-1e618a00-42a4-11ea-8662-8d839e3689c4.png)

The `python` script for `sieve_and_regex` completes in **6.35 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73750540-62acc880-4783-11ea-83a8-ceab78bb0285.png)

The `python` script for `sieve_and_str_check` completes in **4.16 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73750632-84a64b00-4783-11ea-9365-0270834dbbf5.png)

And now, for the **fastest of them all**, `sieve_and_str_check` in `C`. This is *really* damn fast.

The `C` program for `sieve_and_str_check` completes in **0.24 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73750505-4d379e80-4783-11ea-877b-392356750595.png)

yes, ~0.24 seconds. `C` straight up destroys `python` in this one.

# Note

The sieve of eratosthenes method used is a custom implementation of an
improved sieve of eratosthenes algorithm written by Kim Wilsch in C++
"""
 COPYRIGHT NOTICE:-
 BSD 2-Clause License

 Copyright (c) 2010 - 2019, Kim Walisch.
 All rights reserved.
"""
