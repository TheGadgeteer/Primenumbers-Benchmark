public class primetest {
    private static int NUM_PRIMES = 500000;
    public static void main(String args[]) {
        int array[] = new int[NUM_PRIMES];
        boolean isPrime;
        long t1, t2;
        double elapsedMsec;

        t1 = System.nanoTime();
        int i = 2;
        for (int idx = 0; idx < NUM_PRIMES; ++i) {
            isPrime = true;
            for (int y = 0; y < idx; ++y) {
                if (i % array[y] == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                array[idx] = i;
                ++idx;
            }
        }
        t2 = System.nanoTime();
        for(int x = 0; x < 1000; ++x) {
            System.out.print(array[x] + "\t");
        }
        elapsedMsec = (double)(t2 - t1) / 1000;
        System.out.println("\nTime needed for process: " + elapsedMsec + " Milliseconds.");

    }
}
