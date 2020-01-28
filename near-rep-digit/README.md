# Methods
* `sieve_and_str_check` : It uses a   standard segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then a **string comprehension** to check if the prime number is also a near rep digit prime. This is the *fastest* method I came up with.
* `sieve_and_regex` : It uses a   standard segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then 2 **regex expressions** to check if the prime number is also a near rep digit prime. This is the *second fastest* method I came up with.

# Usage
* `sieve_and_str_check.py` : Simply run `python sieve_and_str_check.py` or `python3 sieve_and_str_check`
* `sieve_and_regex.py` : Simply run `python sieve_and_str_check.py` or `python3 sieve_and_str_check`
* `sieve_and_str_check.py` : You can either compile using `MSVC` or `clang` and run the generated executable file

# SPEEEEED!

Here's some benchmarks, This is the *best time* I found running on my PC. `N` (upper limit) is 10,000,000 (10M).

The `python` script for `sieve_and_regex` completes in **11.6 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73118585-0b854780-3f7c-11ea-805d-112b594c9948.png)

The `python` script for `sieve_and_str_check` completes in **9.3 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73118619-9e25e680-3f7c-11ea-82b0-25fb188f3d34.png)

And now, for the **fastest of them all**, `sieve_and_str_check` in `C`. This is *really* damn fast.

The `C` program for `sieve_and_str_check` completes in **0.2 seconds** (best case scenario)

![image](https://user-images.githubusercontent.com/44284917/73118657-007ee700-3f7d-11ea-855f-34ae3936615f.png)

yes, 0.2 seconds. `C` straight up destroys `python` in this one.
