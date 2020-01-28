# Near Repeated Digit Primes Generator
This is collection of curious and kinda cool programs I wrote inspired by [Max Bridgland](https://github.com/M4cs) as he was studying [Glitch Primes](https://www.youtube.com/watch?v=HPfAnX5blO0) and [Near Repeated Digit Primes Generator](https://primes.utm.edu/glossary/page.php?sort=NearRepdigitPrime) in light of the [Riemann Hypothesis](https://en.wikipedia.org/wiki/Riemann_hypothesis).

# Usage
I've used 2 languages for the collection. `python` and `C`. The `C` only uses the best method I came up with, whereas the `python` contains all the methods I encountered during the process.

You can write the python scripts normally just by using `python3` or `python` command.
They use standard libraries so not extra requirements.

The C code can either be compiled through `MSVC` or `CLANG`. It currently should be able to generate glitch primes upto 100B.

# Methods
* `sieve_and_str_check` : It uses a   standard segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then a **string comprehension** to check if the prime number is also a glitch prime. This is the *fastest* method I came up with.
* `sieve_and_regex` : It uses a   standard segmented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) approach and then 2 **regex expressions** to check if the prime number is also a glitch prime. This is the *second fastest* method I came up with.

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
