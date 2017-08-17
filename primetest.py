import time

NUM_PRIMES = 50000
array = list(range(0, NUM_PRIMES))
isPrime = True

t1 = time.time()
i = 2
idx = 0
while (idx < NUM_PRIMES):
    isPrime = True;
    y = 0
    for y in range(0, idx):
        if (i % array[y] == 0):
            isPrime = False
            break
    if (isPrime):
        array[idx] = i
        idx += 1
    i += 1
t2 = time.time()
for x in range(0, 100):
    print(array[x], end="\t")

elapsedMsec = (t2 - t1) * 1000.0;
print("\nTime needed for process:", elapsedMsec, "Milliseconds.");
input()
