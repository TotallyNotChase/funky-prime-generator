# Methods
* `non_sieve_and_unique_set` : It uses a prime check approach and then a **set comprehension** to check if the prime number is also a near rep digit prime. Written by [Max Bridgland](https://github.com/M4cs)
* `sieve_and_str_check` : It uses a standard segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then a **string comprehension** to check if the prime number is also a near rep digit prime. This is the *fastest* method here
* `sieve_and_regex` : It uses a standard segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then 2 **regex expressions** to check if the prime number is also a near rep digit prime. This is the *second fastest* method here

# Usage
* `non_sieve_and_unique_set.py` : Simply run `python non_sieve_and_unique_set.py` or `python3 non_sieve_and_unique_set`
* `sieve_and_str_check.py` : Simply run `python sieve_and_str_check.py` or `python3 sieve_and_str_check`
* `sieve_and_regex.py` : Simply run `python sieve_and_str_check.py` or `python3 sieve_and_str_check`
* `sieve_and_str_check.c` : You can either compile using `MSVC` or `clang` and run the generated executable file

# SPEEEEED!

Here's some benchmarks, This is the *best time* I found running on my PC. `N` (upper limit) is 10,000,000 (10M).

The `python` script for `non_sieve_and_unique_set` completes in **12.8 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73342220-1e618a00-42a4-11ea-8662-8d839e3689c4.png)

The `python` script for `sieve_and_regex` completes in **10.9 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73342103-ef4b1880-42a3-11ea-9bfd-810aa4a3d183.png)

The `python` script for `sieve_and_str_check` completes in **8.7 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73342042-d5a9d100-42a3-11ea-8ebd-fb57f9782506.png)

And now, for the **fastest of them all**, `sieve_and_str_check` in `C`. This is *really* damn fast.

The `C` program for `sieve_and_str_check` completes in **0.2 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73118657-007ee700-3f7d-11ea-855f-34ae3936615f.png)

yes, 0.2 seconds. `C` straight up destroys `python` in this one.
